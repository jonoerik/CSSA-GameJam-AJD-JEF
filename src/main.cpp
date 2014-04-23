#include "libtcod.hpp"
#include <unistd.h>

static size_t width = 150;
static size_t height = 80;

int main(int argc, char* argv[]) {
    TCODConsole::initRoot(width, height, "Escape the Thing", false);
    TCODConsole::flush();
    sleep(10000);
    return 0;
}
