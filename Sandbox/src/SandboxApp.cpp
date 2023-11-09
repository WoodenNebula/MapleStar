#include <Nebulator.h>


class Sandbox : public Nebulator::Application
{
public:
    Sandbox()
    {

    }

    virtual ~Sandbox() override
    {

    }
};

Nebulator::Application* Nebulator::CreateApplication()
{
    return new Sandbox();
}