#pragma once
#if defined _WIN32 || defined _WIN64
  #define WIN32_LEAN_AND_MEAN
  #define _WIN32_WINNT _WIN32_WINNT_WINXP
  #include <windows.h>
#endif
#include <GL/gl3w.h>
#include <GL/GL.h>
#include <GLFW/glfw3.h>

namespace gl_routines
{

bool init();

}