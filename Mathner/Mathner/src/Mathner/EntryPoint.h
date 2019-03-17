#pragma once

#ifdef MN_PLATFORM_WINDOWS

extern Mathner::Application* Mathner::CreateApplication();

int main(int argc, char** argv)
{
	Mathner::Log::Init();
	MN_CORE_INFO("Initialized Log");

	auto app = Mathner::CreateApplication();
	MN_CORE_INFO("Starting Application");

	app->Run();
	
	MN_CORE_INFO("Exiting");
	delete app;
}

#endif // MN_PLATFORM_WINDOWS

