#pragma once

#ifdef MSTAR_PLATFORM_WINDOWS

extern MapleStar::Application* MapleStar::CreateApplication();

int main(int argc, char** argv)
{
    auto app = MapleStar::CreateApplication();

    app->Run();

    delete app;
}

#endif // MSTAR_PLATFORM_WINDOWS