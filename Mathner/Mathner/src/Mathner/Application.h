#pragma once

#include "Mathner/Core.h"

#include "Mathner/Window.h"
#include "Mathner/LayerStack.h"
#include "Mathner/Events/Event.h"
#include "Mathner/Events/ApplicationEvent.h"

#include "Mathner/ImGui/ImGuiLayer.h"

namespace Mathner {

	class MATHNER_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
		
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_IsRunning = true;
		LayerStack m_LayerStack;
		
	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();

}