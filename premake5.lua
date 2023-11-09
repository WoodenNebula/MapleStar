-- Solution details
workspace "Nebulator"
    architecture "x64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
-- Include directories relative to root folder (solution directory)

-- Project: Nebulator details
project "Nebulator"
    location "Nebulator"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "%{prj.name}/src",  
        "%{prj.name}/vendor/spdlog/include",
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "NR_PLATFORM_WINDOWS",
        }

    filter "configurations:Debug"
        defines "NR_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "NR_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "NR_DIST"
        runtime "Release"
        optimize "on"


-- Project: Sandbox details
project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

  
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Nebulator/vendor/spdlog/include",
        "Nebulator/src",
        "Nebulator/vendor",
    }

    links
    {
        "Nebulator"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "NR_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "NR_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "NR_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "NR_DIST"
        runtime "Release"
        optimize "on"