#pragma once

#include <exception>
#include "AssetLoader.hpp"
#include "GLImport.hpp"
#include "XLvlApplication.hpp"

using namespace xlvl;

xlvl::XLvlApplication::XLvlApplication()
{
  if (!glfwInit())
    throw std::exception("Couldn't initialize GLFW");
  this->_window = glfwCreateWindow(1280, 720, "xlvl", nullptr, nullptr);
  if (!this->_window)
  {
    glfwTerminate();
    throw std::exception("Couldn't create GLFW window");
  }

  glfwMakeContextCurrent(this->_window);
  if (gl3wInit() == -1)
    throw std::exception("Couldn't initialize gl3w");
  this->_assetLoader = std::make_shared<AssetLoader>("assets/");
}

xlvl::XLvlApplication::~XLvlApplication()
{
  glfwTerminate();
}

void xlvl::XLvlApplication::run()
{
  while (!glfwWindowShouldClose(this->_window))
  {
    glfwSwapBuffers(this->_window);
    glfwPollEvents();
  }
}