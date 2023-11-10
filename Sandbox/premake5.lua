-- Project: Sandbox details
project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

  
    files
    {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs
    {
        "%{wks.location}/%{wks.name}/vendor/spdlog/include",
        "%{wks.location}/%{wks.name}/src",
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