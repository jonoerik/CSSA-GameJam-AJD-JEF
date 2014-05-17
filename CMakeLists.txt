cmake_minimum_required(VERSION 2.8)
project(EscapeTheThings)

# Source files

set(SRC_DIR src)
set(HEADER_DIR src)
set(SRC_MAIN
    main.cpp
)
set(SRC_MAIN_MAPGENTEST
    MapGenTest.cpp
)
set(SRC_FILES
    Drone.cpp
    Map.cpp
    MapGen.cpp
    Player.cpp
)
set(HEADER_FILES
    Drone.hpp
    Map.hpp
    MapGen.hpp
    Player.hpp
    Vector2D.hpp
)

set(OUTPUT_EXE EscapeTheThings)
set(OUTPUT_EXE_MAPGENTEST MapGenTest)

# Build libtcod

include(ExternalProject)
ExternalProject_Add(
    libtcod
    PREFIX libtcod
    HG_REPOSITORY https://bitbucket.org/jice/libtcod
    UPDATE_COMMAND ""
    PATCH_COMMAND ""
    CONFIGURE_COMMAND ""
    BUILD_IN_SOURCE 1
    BUILD_COMMAND $(MAKE) -f ./makefiles/makefile-linux COMMAND $(MAKE) -f ./makefiles/makefile-linux libtcod.a libtcodxx.a COMMAND cp ./terminal.png ${CMAKE_CURRENT_BINARY_DIR}
    INSTALL_COMMAND ""
    TEST_COMMAND ""
)
ExternalProject_Get_Property(libtcod BINARY_DIR)
list(APPEND LIB_FILES_FULL "${BINARY_DIR}/libtcodxx.a")
list(APPEND LIB_FILES_FULL "${BINARY_DIR}/libtcod.a")
list(APPEND LIB_INCLUDE_DIRS_FULL "${BINARY_DIR}/include")

# Set up full paths

set(SRC_DIR_FULL "${CMAKE_SOURCE_DIR}/${SRC_DIR}")
set(HEADER_DIR_FULL "${CMAKE_SOURCE_DIR}/${HEADER_DIR}")
set(SRC_MAIN_FULL "${CMAKE_SOURCE_DIR}/${SRC_DIR}/${SRC_MAIN}")
set(SRC_MAIN_MAPGENTEST_FULL "${CMAKE_SOURCE_DIR}/${SRC_DIR}/${SRC_MAIN_MAPGENTEST}")
foreach(f ${SRC_FILES})
    list(APPEND SRC_FILES_FULL "${CMAKE_SOURCE_DIR}/${SRC_DIR}/${f}")
endforeach()
foreach(f ${HEADER_FILES})
    list(APPEND HEADER_FILES_FULL "${CMAKE_SOURCE_DIR}/${HEADER_DIR}/${f}")
endforeach()

# Build executable

add_definitions( -std=c++11 )
include_directories(${HEADER_DIR_FULL})
include_directories(${LIB_INCLUDE_DIRS_FULL})
add_executable(${OUTPUT_EXE} ${SRC_MAIN_FULL} ${SRC_FILES_FULL} ${HEADER_FILES_FULL})
add_executable(${OUTPUT_EXE_MAPGENTEST} ${SRC_MAIN_MAPGENTEST_FULL} ${SRC_FILES_FULL} ${HEADER_FILES_FULL})
target_link_libraries(${OUTPUT_EXE} ${LIB_FILES_FULL})
target_link_libraries(${OUTPUT_EXE_MAPGENTEST} ${LIB_FILES_FULL})
add_dependencies(${OUTPUT_EXE} libtcod)
add_dependencies(${OUTPUT_EXE_MAPGENTEST} libtcod)

# System libraries

find_package(SDL)
include_directories(${SDL_INCLUDE_DIR})
target_link_libraries(${OUTPUT_EXE} ${SDL_LIBRARY})
target_link_libraries(${OUTPUT_EXE_MAPGENTEST} ${SDL_LIBRARY})
find_package(OpenGL)
include_directories(${OPENGL_INCLUDE_DIR})
target_link_libraries(${OUTPUT_EXE} ${OPENGL_LIBRARIES})
target_link_libraries(${OUTPUT_EXE_MAPGENTEST} ${OPENGL_LIBRARIES})

target_link_libraries(${OUTPUT_EXE} dl)
target_link_libraries(${OUTPUT_EXE_MAPGENTEST} dl)
