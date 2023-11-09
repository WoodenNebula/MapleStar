#include <MapleStar.h>


class Sandbox : public MapleStar::Application
{
public:
    Sandbox()
    {

    }

    virtual ~Sandbox() override
    {

    }
};

MapleStar::Application* MapleStar::CreateApplication()
{
    return new Sandbox();
}