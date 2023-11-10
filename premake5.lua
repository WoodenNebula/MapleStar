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


group "Core"
    include "Nebulator"

group ""

group "App"
    include "Sandbox"

group ""