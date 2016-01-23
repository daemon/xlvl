#include "AssetLoader.hpp"
#include "Scene.hpp"

using namespace xlvl;

Scene::Camera &Scene::Camera::setView(glm::mat4 view)
{
  this->view = std::move(view);
  return *this;
}

Scene::Camera &Scene::Camera::setProj(glm::mat4 proj)
{
  this->proj = std::move(proj);
  return *this;
}

Scene::Scene(std::shared_ptr<AssetLoader> loader) : _loader(loader)
{
}