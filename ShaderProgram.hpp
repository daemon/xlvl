#pragma once
#include "GLImport.hpp"
#include <istream>
#include <utility>

class ShaderProgram
{
public:
  ShaderProgram(std::istream &stream, GLenum shaderType);
  GLint attribLocation(const std::string &name) const;
  void use() const;
private:
  GLuint _shaderId;
  GLuint _shaderProgram;
};