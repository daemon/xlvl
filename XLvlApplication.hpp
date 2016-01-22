#pragma once

#include <memory>
#include "AssetLoader.hpp"
#include "GLImport.hpp"

namespace xlvl
{

class XLvlApplication
{
public:
  XLvlApplication();
  ~XLvlApplication();
  void run();

private:
  GLFWwindow *_window;
  std::shared_ptr<AssetLoader> _assetLoader;
};

}