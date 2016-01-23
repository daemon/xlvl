#pragma once

#include <exception>
#include "AssetLoader.hpp"
#include "GLImport.hpp"
#include "ScreenManager.hpp"
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
  this->_screenManager = std::move(std::unique_ptr<ScreenManager>(new ScreenManager(this->_window, 60)));
}

xlvl::XLvlApplication::~XLvlApplication()
{
  glfwTerminate();
}

void xlvl::XLvlApplication::run()
{
  this->_screenManager->run();
}