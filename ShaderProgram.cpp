#include <sstream>
#include "ShaderProgram.hpp"

ShaderProgram::ShaderProgram(std::initializer_list<std::pair<std::istream &, GLenum>> shaders)
{  
  this->_shaderProgram = glCreateProgram();
  for (auto &shader : shaders)
  {
    std::stringstream ss;
    std::string line;
    while (std::getline(shader.first, line))
      ss << line;
    GLuint shaderId = glCreateShader(shader.second);
    std::string str(ss.str());
    const char *shaderCStr = str.c_str();
    const GLint len[1] = { 1 };
    glShaderSource(shaderId, 1, &shaderCStr, len);
    glCompileShader(shaderId);

    GLint rc;
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &rc);
    if (rc == GL_FALSE)
      throw std::exception("Failed to compile shader");
    glAttachShader(this->_shaderProgram, shaderId);
    this->_shaders.push_back(shaderId);
  }
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

ShaderProgram &ShaderProgram::operator+(const ShaderProgram &other)
{
  this->_shaders.insert(this->_shaders.end(), other._shaders.begin(), other._shaders.end());
  this->_shaderProgram = glCreateProgram();
  for (auto shaderId : other._shaders)
    glAttachShader(this->_shaderProgram, shaderId);
  return *this;
}

ShaderProgram::~ShaderProgram()
{
  glDeleteProgram(this->_shaderProgram);
}