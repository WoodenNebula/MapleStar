#pragma once

#include "nrpch.h"
#include "Window.h"
#include "Nebulator/Events/Event.h"

namespace Nebulator {

    class Application
    {
    public:
        Application();

        virtual ~Application();

        void OnEvent(Event& e);

        void Run();

    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };

    // To be defined in client
    Application* CreateApplication();
}