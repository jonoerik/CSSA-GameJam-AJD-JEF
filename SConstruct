# Ogre specific scons details from http://www.ogre3d.org/tikiwiki/tiki-index.php?page=Setting+Up+An+Application+-+Linux+-+Shoggoth

# Settings
src_dir = "src"
src_files = Split("""
main.cpp
""")

build_dir = "build"
target = "main"



from os import path

env = Environment(CC = "gcc",
                  CCFLAGS = "-O2")
env.VariantDir(build_dir + "/", src_dir + "/")

# Check external libs
env.ParseConfig('pkg-config --silence-errors --libs --cflags OGRE || true')
env.ParseConfig('pkg-config --silence-errors --libs --cflags OIS || true')

config = Configure(env);

# Check OIS is installed
if not config.CheckLibWithHeader('OIS', 'OISPrereqs.h', 'C++'):
    print 'OIS must be installed!'
    Exit(1)
    
# Check Ogre is installed
if not config.CheckLibWithHeader( 'OgreMain', 'Ogre.h', 'C++' ):
    print "Ogre Must be installed!"
    Exit(1)
    
env = config.Finish(); 

env.Program(target, [path.join(build_dir, f) for f in src_files])
