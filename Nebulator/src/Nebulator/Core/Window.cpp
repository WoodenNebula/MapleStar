#include "nrpch.h"
#include "Window.h"

#include "Glad/glad.h"
#include "GLFW/glfw3.h"

namespace Nebulator {

    Window* Window::Create(const WindowProps& props)
    {
        return new Window(props);
    }


    Window::Window(const WindowProps& props)
    {
        Init(props);
    }


    Window::~Window()
    {
        Shutdown();
    }


    void Window::SetEventCallback(const EventCallbackFunc& cbFunc)
    {

    }

    static std::string glTypeDecoder(const GLenum& type)
    {
        switch (type)
        {
        case GL_DEBUG_TYPE_ERROR:
            return "ERROR";
        case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
            return "DEPRECATED_BEHAVIOR";
        case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
            return "UNDEFINED_BEHAVIOR";
        default:
            return "OTHER";
        }
        return "NONE";
    }


    bool Window::m_IsFullScrreen = false;

    /// TODO: IMPLEMENT EVENT HANDLING
    void Window::Init(const WindowProps& props)
    {
        // GLFW Initialization
        {
            // Setting Error callback for GLFW functions
            glfwSetErrorCallback([](int errCode, const char* errMsg)
                {
                    NR_CORE_ERROR("GLFW ({0}) : {1}" , errCode, errMsg);
                    NR_ASSERT(false);
                });


            if (glfwInit() == GLFW_TRUE)
            {
                NR_CORE_INFO("GLFW : INITIALIZATION SUCCESSFUL!");
            }
            else
            {
                NR_CORE_ERROR("GLFW : INITIALIZATION FAILED!");
                NR_ASSERT(false);
            }

            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

            #ifdef _DEBUG
                glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
            #endif
        }
        //--GLFW Initialization------------------



        //--Window Creation----------------------
        {
            m_Data.Title = props.Title;
            m_Data.Height = props.Height;
            m_Data.Width = props.Width;

            m_WindowHandle = glfwCreateWindow((int)props.Width, (int)props.Height, props.Title.c_str(), NULL, NULL);

            if (m_WindowHandle == NULL)
            {
                NR_CORE_ERROR("[Window] : Window Creation Failed");
                glfwTerminate();
            }

            glfwMakeContextCurrent(m_WindowHandle);

            glfwSetWindowUserPointer(m_WindowHandle, &m_Data);
            SetVSync(true);

        }
        //--Window Creation----------------------



        // GLAD Initialization
        {
            if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
            {
                //Problem: glewInit failed, something is seriously wrong.
                NR_ERROR("Glad Initialization failed, aborting");
                glfwTerminate();
            }
        } //--GLAD Initialization----------------


        //--OpenGL Setup-------------------------
        {
            #ifdef NR_DEBUG
                glEnable(GL_DEBUG_OUTPUT);
            #endif // NR_DEBUG


            glDebugMessageCallback([](GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const char* message,
                const void* userParam)
                {
                    if (severity == GL_DEBUG_SEVERITY_MEDIUM || severity == GL_DEBUG_SEVERITY_LOW)
                        NR_CORE_WARN("[GL] : ({0} - {1}) -> {2}", id, glTypeDecoder(type), message);

                    if (severity == GL_DEBUG_SEVERITY_HIGH)
                        NR_CORE_ERROR("[GL] : ({0} - {1}) -> {2}", id, glTypeDecoder(type), message);

                }, (void*)0);


            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

            glViewport(0, 0, m_Data.Width, m_Data.Height);
        } //--OpenGL Setup-----------------------




        //--GLFW Callbacks-----------------------
        {
            glfwSetFramebufferSizeCallback(m_WindowHandle, [](GLFWwindow* window, int newWidth, int newHeight)
                {
                    glViewport(0, 0, newWidth, newHeight);
                    WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

                    data.Height = newHeight;
                    data.Width = newWidth;
                });


            glfwSetKeyCallback(m_WindowHandle, [](GLFWwindow* window, int key, int scancode, int action, int mods)
                {
                    // Exit on ESC
                    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
                    {
                        glfwSetWindowShouldClose(window, true);
                        NR_CORE_INFO("ESC pressed, exiting application");
                    }

                    // Fullscreen Windows
                    if (key == GLFW_KEY_F11 && action == GLFW_PRESS)
                    {
                        GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();

                        static int lastWidth = 0, lastHeight = 0;
                        static int lastX = 0, lastY = 0;


                        if (!m_IsFullScrreen)
                        {
                            //Saving windowed dimensions for later
                            glfwGetWindowSize(window, &lastWidth, &lastHeight);
                            glfwGetWindowPos(window, &lastX, &lastY);

                            glfwSetWindowMonitor(window, primaryMonitor, NULL, NULL, 1366, 768, 60);
                            NR_CORE_TRACE("F11 PRESSED! CHANGED INTO FULLSCREEN.");
                            m_IsFullScrreen = true;
                        }
                        else if (m_IsFullScrreen)
                        {

                            glfwSetWindowMonitor(window, nullptr, lastX, lastY, lastWidth, lastHeight, 60);
                            NR_CORE_TRACE("F11 PRESSED! CHANGED INTO WINDOWED");
                            m_IsFullScrreen = false;
                        }

                    }

                });


            glfwSetMouseButtonCallback(m_WindowHandle, [](GLFWwindow* window, int button, int action, int mods)
                {
                    // Mouse Click Collision Check
                    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
                    {
                    }
                });

        } //--GLFW Callbacks-----------------------

    } //--Window Init----------------------------


    void Window::OnUpdate()
    {
        /* Poll for events and processes */
        glfwPollEvents();

        /* Swap front and back buffers */
        glfwSwapBuffers(m_WindowHandle);
    }

    void Window::SetVSync(bool enabled)
    {
        if (enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);

        m_Data.VSync = enabled;
    }


    void Window::Shutdown()
    {
        glfwDestroyWindow(m_WindowHandle);

        glfwTerminate();

    }
} // namespace Nebulator