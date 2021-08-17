#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Events/Event.h"
#include "Log.h"


namespace Pip {

	Application::Application()
	{

	}
	Application::~Application()
	{

	}


	void Application::Run()
	{
		//test
		WindowResizeEvent e(1920, 720);
		PIP_TRACE(e);
		while (true);
	}
}