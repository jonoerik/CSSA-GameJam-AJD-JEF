# Settings
src_dir = "src"
src_files = Split("""
Vector2D.hpp
MapGen.hpp
MapGen.cpp
Map.hpp
Map.cpp
Drone.hpp
Drone.cpp
Player.hpp
Player.cpp
""")

build_dir = "build"
targets = [
["main", "main.cpp"],
["MapGenTest", "MapGenTest.cpp"]
]

libs = [
"libtcodxx.a",
"libtcod.a",
"SDL",
"GL"
]
libpath = "lib/jice-libtcod-d56ffc19afb9"

includepaths = [
"lib/jice-libtcod-d56ffc19afb9/include"
]

from os import path

env = Environment(CC = "gcc",
                  CCFLAGS = "-O2 -std=c++11",
                  LINKFLAGS = "-O2 -std=c++11",
		  CPPPATH = includepaths)
env.VariantDir(build_dir + "/", src_dir + "/")
env.Command("lib/jice-libtcod-d56ffc19afb9/libtcodxx.a", "", "cd lib/jice-libtcod-d56ffc19afb9 && make -f makefiles/makefile-linux64 libtcodxx.a")
env.Command("lib/jice-libtcod-d56ffc19afb9/libtcod.a", "", "cd lib/jice-libtcod-d56ffc19afb9 && make -f makefiles/makefile-linux64 libtcod.a")

for target in targets:
    env.Program(target=target[0], source=[path.join(build_dir, f) for f in src_files + [target[1]]], LIBS=libs, LIBPATH=libpath)
