#include <memory>
#include "AssetLoader.hpp"

namespace xlvl
{

class IntroMenu
{
public:
  IntroMenu(AssetLoader *loader);
private:
  ShaderProgram _flat2d;
};

}