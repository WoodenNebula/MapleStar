#pragma once

#ifdef NR_PLATFORM_WINDOWS

extern Nebulator::Application* Nebulator::CreateApplication();

int main(int argc, char** argv)
{
    Nebulator::Log::Init();

    NR_CORE_INFO("Initialized Logger!");

    auto app = Nebulator::CreateApplication();

    app->Run();

    delete app;
}

#endif // NR_PLATFORM_WINDOWS