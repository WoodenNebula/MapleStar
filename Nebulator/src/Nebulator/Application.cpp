#include "Application.h"

#include "Log.h"

namespace Nebulator {

    Application::Application() {}

    Application::~Application() {}

    void Application::Run()
    {
        NR_INFO("STARTED APPLICATION");
        while (true);
    }

}