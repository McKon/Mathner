#include <Mathner.h>

class ExampleLayer : public Mathner::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		MN_INFO("ExampleLayer::Update");
		if (Mathner::Input::IsKeyPressed(MN_KEY_TAB))
			MN_TRACE("Tab key is pressed");
	}

	void OnEvent(Mathner::Event& event) override
	{
		//MN_TRACE("{0}", event);
	}
};

class Sandbox : public Mathner::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Mathner::ImGuiLayer());
	}

	~Sandbox()
	{

	}

};

Mathner::Application* Mathner::CreateApplication()
{
	return new Sandbox();
}