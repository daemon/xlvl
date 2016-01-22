#pragma once
#if defined _WIN32 || defined _WIN64
  #include <windows.h>
#endif
#include <GL/gl3w.h>
#include <GL/GL.h>
#include <GLFW/glfw3.h>

namespace gl_routines
{

bool init();

}