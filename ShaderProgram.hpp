#pragma once
#include "GLImport.hpp"
#include <istream>
#include <utility>
#include <vector>

class ShaderProgram
{
public:
  ShaderProgram::ShaderProgram(std::initializer_list<std::pair<std::istream &, GLenum>> shaders);
  ShaderProgram::ShaderProgram(std::istream &in, GLenum shaderType) : ShaderProgram({{in, shaderType}}) {}
  ShaderProgram::~ShaderProgram();
  GLint attribLocation(const std::string &name) const;
  ShaderProgram &operator+(const ShaderProgram &other);
  void use() const;
private:
  std::vector<GLuint> _shaders;
  GLuint _shaderProgram;
};