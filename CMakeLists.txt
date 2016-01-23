cmake_minimum_required(VERSION 2.6)
project(xlvl-project)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# GLFW
add_subdirectory($ENV{GLFW-DIR} lib/glfw)
include_directories($ENV{GLFW-DIR}/include)

# GLM
include_directories($ENV{GLM-DIR})

# GL3W
include_directories($ENV{GL3W-DIR})
link_directories($ENV{GL3W-DIR})

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

if (CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "-Wall -O2 -s -std=c++11")
endif (CMAKE_COMPILER_IS_GNUCXX)

add_executable(xlvl Main.cpp XLvlApplication.cpp XLvlApplication.hpp ShaderProgram.cpp GLImport.hpp ShaderProgram.hpp AssetLoader.hpp AssetLoader.cpp ScreenManager.hpp ScreenManager.cpp DrawObject.hpp)
target_link_libraries(xlvl glfw ${OPENGL_glu_LIBRARY} ${GLFW_LIBRARIES} gl3w)