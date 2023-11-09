#pragma once

#ifdef MSTAR_PLATFORM_WINDOWS

extern MapleStar::Application* MapleStar::CreateApplication();

int main(int argc, char** argv)
{
    MapleStar::Log::Init();

    MSTAR_CORE_INFO("Initialized Logger!");

    int x = 69;
    MSTAR_TRACE("Welcome to MapleStar! {0}", x);

    auto app = MapleStar::CreateApplication();

    app->Run();

    delete app;
}

#endif // MSTAR_PLATFORM_WINDOWS