#include "nrpch.h"
#include "Nebulator\Core\Core.h"
#include "Application.h"
#include "Nebulator\Events\WindowEvent.h"

namespace Nebulator {

    Application::Application() {}

    Application::~Application() {}

    void Application::Run()
    {
        NR_INFO("STARTED APPLICATION");

        WindowResizedEvent e(1336, 720);

        if (e.IsInEventCategory(EventCategory::KeyboardEvents))
        {
            NR_TRACE("KEYBOARD EVENT");
        }
        else if (e.IsInEventCategory(EventCategory::WindowEvents))
        {
            NR_TRACE(e);
        }

        while (true);
    }

}