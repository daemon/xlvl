#include <sstream>
#include "ShaderProgram.hpp"

ShaderProgram::ShaderProgram(std::istream &stream, GLenum shaderType)
{  
  std::stringstream ss;
  std::string line;
  while (std::getline(stream, line))
    ss << line;
  this->_shaderId = glCreateShader(shaderType);
  std::string str(ss.str());
  const char *shaderCStr = str.c_str();
  const GLint len[1] = {1};
  glShaderSource(this->_shaderId, 1, &shaderCStr, len);
  glCompileShader(this->_shaderId);

  GLint rc;
  glGetShaderiv(this->_shaderId, GL_COMPILE_STATUS, &rc);
  if (rc == GL_FALSE)
    throw std::exception("Failed to compile shader");

  this->_shaderProgram = glCreateProgram();
  glAttachShader(this->_shaderProgram, this->_shaderId);
}

GLint ShaderProgram::attribLocation(const std::string &name) const
{
  GLint loc = glGetAttribLocation(this->_shaderProgram, name.c_str());
  if (loc == -1)
    throw std::exception("Couldn't find attrib");
  return loc;
}

void ShaderProgram::use() const
{
  glUseProgram(this->_shaderProgram);
}