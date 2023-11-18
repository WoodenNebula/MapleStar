#include "nrpch.h"
#include "Application.h"
#include "Nebulator/Core/Log.h"
#include "Nebulator/Events/WindowEvent.h"
#include <GLFW/glfw3.h>


namespace Nebulator {

    #define BIND_EVENT_FUNC(x) std::bind(&Application::x, this, std::placeholders::_1)

    Application::Application() 
        :m_Running(true)
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(BIND_EVENT_FUNC(OnEvent));
    }

    Application::~Application() {}

    void Application::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);

        //dispatcher.Dispatch<WindowClosedEvent>(BIND_EVENT_FUNC("OnWindowClose"));
    }

    void Application::Run()
    {
        NR_INFO("STARTED APPLICATION");
        while (m_Running)
        {
            glClearColor(0.69f, 0.069f, 0.69f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            m_Window->OnUpdate();
        }
    }

}