#include "mnpch.h"
#include "Application.h"

#include "Mathner/Log.h"

#include <glad/glad.h>

#include <chrono>


namespace Mathner {



	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		MN_CORE_ASSERT(!s_Instance, "Instance of Application already initialized")
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(MN_BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application()
	{

	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(MN_BIND_EVENT_FN(Application::OnWindowClose));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.m_Handled)
				break;
		}

	}

	void Application::Run()
	{
		auto last = std::chrono::high_resolution_clock::now();
		while (m_IsRunning)
		{
			auto current = std::chrono::high_resolution_clock::now();
			std::chrono::duration<float> duration = current - last;
			MN_CORE_INFO("Frames per second: {0}", 1/duration.count());
//			MN_CORE_INFO("Time elapsed this frame: {0}", duration.count());
			last = current;


			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();
			
			m_Window->OnUpdate();
		}

	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_IsRunning = false;

		return true;
	}

}