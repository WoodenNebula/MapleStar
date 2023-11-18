include "Dependencies.lua"

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

include "Nebulator/vendor/GLFW"
include "Nebulator/vendor/Glad"
include "Nebulator"
include "Sandbox"
