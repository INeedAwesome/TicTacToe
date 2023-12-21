project "TicTacToe"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++20"
   staticruntime "off"

   files { "src/**.h", "src/**.cpp" }

   includedirs
   {
      "src/"
   }

   targetdir ("../bin/" .. outputdir .. "-%{prj.name}")
   objdir ("../bin-int/" .. outputdir .. "-%{prj.name}")

   filter "system:windows"
      systemversion "latest"
      defines { "T_PLATFORM_WINDOWS" }
   filter "system:linux"
      systemversion "latest"
      defines { "T_PLATFORM_LINUX" }

   filter "configurations:Debug"
      defines { "T_DEBUG" }
      runtime "Debug"
      symbols "On"

   filter "configurations:Release"
      defines { "T_RELEASE" }
      runtime "Release"
      optimize "On"
      symbols "On"

   filter "configurations:Dist"
      kind "WindowedApp"
      defines { "T_DIST" }
      runtime "Release"
      optimize "Speed"
      symbols "Off"
