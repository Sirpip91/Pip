workspace "Pip"
	architecture "x64"
		startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	outputdir = "%{cfg.buildcfg}%{cfg.system}-%{cfg.architecture}"

project "Pip"
	location "Pip"
	kind "SharedLib"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "pippch.h"
	pchsource "Pip/src/pippch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/OutsideVend/spdlog/include;"
	}

	filter "system:windows"
	cppdialect "C++17"
	staticruntime "On"
	systemversion "latest"

	defines
	{
	"PIP_PLATFORM_WINDOWS",
	"PIP_BUILD_DLL"
	}

	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
	}

	filter "configurations:Debug"
		defines "PIP_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PIP_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PIP_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Pip/OutsideVend/spdlog/include;",
		"Pip/src"
	}

	links
	{
		"Pip"
	}

	defines
	{
		"PIP_PLATFORM_WINDOWS"
	}

	filter "configurations:Debug"
		defines "PIP_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PIP_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PIP_DIST"
		optimize "On"

	