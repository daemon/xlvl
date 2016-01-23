#include <memory>
#include "Scene.hpp"
#include "ShaderProgram.hpp"

namespace xlvl
{

class IntroMenu : public Scene
{
public:
  IntroMenu(std::shared_ptr<AssetLoader> loader);
private:
  void _draw() override;
  ShaderProgram _defaultProg;
};

}