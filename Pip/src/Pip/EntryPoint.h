#pragma once

#ifdef PIP_PLATFORM_WINDOWS

extern Pip::Application* Pip::CreateApplication();

int main()
{
	printf("PIP ENGINENINEINEI");
	auto app = Pip::CreateApplication();
	app->Run();
	delete app;
}

#endif