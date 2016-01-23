#include <algorithm>
#include <thread>
#include "ScreenManager.hpp"

using namespace xlvl;

void xlvl::ScreenManager::run()
{
  double targetDelay = 1000.0 / this->_fpsHint;
  while (!glfwWindowShouldClose(this->_window))
  {
    auto a = std::chrono::steady_clock::now();
    this->_draw();
    auto b = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> dur = b - a;
    this->_realFps = 1000.0 / dur.count();
    targetDelay = targetDelay * 0.8 + std::max<double>(targetDelay - dur.count(), 0.0) * 0.2;
    glfwSwapBuffers(this->_window);
    glfwPollEvents();
    std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(targetDelay)));
  }
}

void xlvl::ScreenManager::_draw()
{
  for (auto &obj : this->_objects)
    obj->draw();
}