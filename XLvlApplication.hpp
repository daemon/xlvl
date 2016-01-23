#pragma once

#include <memory>
#include "AssetLoader.hpp"
#include "GLImport.hpp"

namespace xlvl
{

class ScreenManager;

class XLvlApplication
{
public:
  XLvlApplication();
  ~XLvlApplication();
  void run();

private:
  GLFWwindow *_window;
  std::shared_ptr<AssetLoader> _assetLoader;
  std::unique_ptr<ScreenManager> _screenManager;
};

}