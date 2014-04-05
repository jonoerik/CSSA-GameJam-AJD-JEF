from os import path

src_dir = "src"
src_files = Split("""
main.cpp
""")
build_dir = "build"
target = "main"

env = Environment(CC = "gcc",
                  CCFLAGS = "-O2")
env.VariantDir(build_dir + "/", src_dir + "/")
env.Program(target, [path.join(build_dir, f) for f in src_files])
