#pragma once
#include "Nebulator/Events/Event.h"

struct GLFWwindow;

namespace Nebulator {

    struct WindowProps
    {
        std::string Title;
        uint32_t Width, Height;

        WindowProps(const std::string& title = "Nebulator", uint32_t width = 800, uint32_t height = 720)
            :Title(title), Width(width), Height(height)
        {}
    };


    class Window
    {
    public:
        using EventCallbackFunc = std::function<void(Event&)>;

        Window(const WindowProps& props);
        ~Window();

        static Window* Create(const WindowProps& props = WindowProps());

        void OnUpdate();

        inline GLFWwindow* GetWindowHandle() const { return m_WindowHandle; }

        inline uint32_t GetWidth() const { return m_Data.Width; }
        inline uint32_t GetHeight() const { return m_Data.Height; }

        void SetEventCallback(const EventCallbackFunc& cbFunc);
        void SetVSync(bool enabled);
        inline bool IsVSync() const { return m_Data.VSync; }

    private:
        /// TODO : further abstract error cases 
        void Init(const WindowProps& props);
        void Shutdown();


    private:
        GLFWwindow* m_WindowHandle;
        struct WindowData
        {
            std::string Title;
            uint32_t Width, Height;
            bool VSync;

            EventCallbackFunc EventCbFunc;
        };

        WindowData m_Data;
        static bool m_IsFullScrreen;
    };
} // namespace Nebulator