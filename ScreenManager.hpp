#pragma once
#include <memory>
#include <vector>
#include "DrawObject.hpp"
#include "GLImport.hpp"

namespace xlvl
{

class ScreenManager : public DrawingObject
{
public:
  ScreenManager(GLFWwindow *window, unsigned int fpsHint) : _window(window), _fpsHint(fpsHint), _realFps(0) {}
  void run();
  void regDrawingObject(std::shared_ptr<DrawingObject> object) { this->_objects.push_back(object); }
private:
  void _draw();
  GLFWwindow *_window;
  std::vector<std::shared_ptr<DrawingObject>> _objects;
  unsigned int _fpsHint;
  unsigned int _realFps;
};

}