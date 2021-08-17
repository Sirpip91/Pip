#pragma once

#ifdef PIP_PLATFORM_WINDOWS
	#ifdef PIP_BUILD_DLL
		#define PIP_API __declspec(dllexport)
	#else
		#define PIP_API __declspec(dllimport)
	#endif 
#else
	#error Pip only supports windows sorry :(

#endif 


#define  BIT(x) (1 << x)