#include "GLImport.hpp"

using namespace gl_routines;

bool gl_routines::init()
{
  static bool ini = glfwInit();
  return ini;
}