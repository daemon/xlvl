#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <memory>
#include <vector>
#include "DrawObject.hpp"

namespace xlvl
{

class AssetLoader;

class Scene : public DrawingObject
{
public:
  struct Camera
  {
    Camera &setView(glm::mat4 view);
    Camera &setProj(glm::mat4 proj);
    glm::mat4 view;
    glm::mat4 proj;
  };

  class Object : public DrawingObject
  {
  public:
    glm::vec3 &center() { return this->_center; }
    void setScene(std::weak_ptr<Scene> scene) { this->_scene = scene; }
    std::weak_ptr<Scene> scene() { return this->_scene; }
  private:
    glm::vec3 _center;
    std::weak_ptr<Scene> _scene;
  };

  Scene(std::shared_ptr<AssetLoader> loader);

  Camera& camera() { return this->_camera; }
  void addObject(std::shared_ptr<Object> object) { this->_objects.push_back(object); }
  std::shared_ptr<AssetLoader> assetLoader() { return this->_loader; }
  std::vector<std::shared_ptr<Object>> &objects() { return this->_objects; }
private:
  Scene::Camera _camera;
  std::vector<std::shared_ptr<Object>> _objects;
  std::shared_ptr<AssetLoader> _loader;
};
}