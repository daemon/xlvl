#include "AssetLoader.hpp"
#include "GLImport.hpp"
#include "IntroMenu.hpp"

using namespace xlvl;

xlvl::IntroMenu::IntroMenu(std::shared_ptr<AssetLoader> loader)
  : Scene(loader), 
  _defaultProg(loader->vertexShader("default") + loader->fragmentShader("default"))
{
}

void xlvl::IntroMenu::_draw()
{
  glClearColor(0, 0, 0, 0);
  for (auto &objPtr : this->objects())
  {
    this->_defaultProg.use();
    objPtr->draw();
  }
}