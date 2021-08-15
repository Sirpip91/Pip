#pragma once

#ifdef PIP_PLATFORM_WINDOWS

extern Pip::Application* Pip::CreateApplication();

int main()
{
	Pip::Log::Init();
	PIP_CORE_WARN("INITIALIZED LOG");
	int a = 5;
	PIP_INFO("hello ! Var={0}", a);

	auto app = Pip::CreateApplication();
	app->Run();
	delete app;
}

#endif

