#pragma once

#include "Mathner/Layer.h"

#include "Mathner/Events/ApplicationEvent.h"
#include "Mathner/Events/KeyEvents.h"
#include "Mathner/Events/MouseEvents.h"

namespace Mathner {

	class MATHNER_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;
	
		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};
}