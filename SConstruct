# Settings
src_dir = "src"
src_files = Split("""
Vector2D.hpp
MapGen.hpp
MapGen.cpp
""")

build_dir = "build"
targets = [
["main", "main.cpp"],
["MapGenTest", "MapGenTest.cpp"]
]

libs = [
"libtcodxx.a"
]
libpath = "lib/jice-libtcod-d56ffc19afb9"

from os import path

env = Environment(CC = "gcc",
                  CCFLAGS = "-O2 -std=c++11",
                  LINKFLAGS = "-O2 -std=c++11")
env.VariantDir(build_dir + "/", src_dir + "/")
env.Command("lib/jice-libtcod-d56ffc19afb9/libtcodxx.a", "", "cd lib/jice-libtcod-d56ffc19afb9 && make -f makefiles/makefile-linux64 libtcodxx.a")

for target in targets:
    env.Program(target=target[0], source=[path.join(build_dir, f) for f in src_files + [target[1]]], LIBS=libs, LIBPATH=libpath)
