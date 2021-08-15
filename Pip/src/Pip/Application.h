#pragma once
#include "Core.h"

namespace Pip {
	class PIP_API Application
	{

	public:
		Application();
		virtual ~Application();

	void Run();
	};


	//defined in entyrpoint In Client

	Application* CreateApplication();
}

