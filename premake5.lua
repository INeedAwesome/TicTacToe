workspace "TicTacToe"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "TicTacToe"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "TicTacToe"