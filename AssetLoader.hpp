#pragma once

#include <string>
#include <unordered_map>
#include "ShaderProgram.hpp"

namespace xlvl
{

class AssetLoader
{
public:
  AssetLoader(const std::string &folderPath);
  ShaderProgram &vertexShader(const std::string &name) { return this->_nameToVertexProgram.at(name); }
  ShaderProgram &fragmentShader(const std::string &name) { return this->_nameToFragProgram.at(name); }
private:
  std::unordered_map<std::string, ShaderProgram> _nameToVertexProgram;
  std::unordered_map<std::string, ShaderProgram> _nameToFragProgram;
};

}