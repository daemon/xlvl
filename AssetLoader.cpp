#include <fstream>
#include <cinttypes>
#include <memory>
#include "AssetLoader.hpp"
#include "dirent.h"

using namespace xlvl;

xlvl::AssetLoader::AssetLoader(const std::string &folderPath)
{
  DIR *dir;
  struct dirent *ent;
  if ((dir = opendir(folderPath.c_str())) != nullptr)
  {
    while ((ent = readdir(dir)) != nullptr)
      if (ent->d_type == DT_REG)
      {
        std::string name(ent->d_name, ent->d_namlen);
        if (name.length() < 4)
          continue;
        if (name.rfind(".vs") == name.length() - 3)
        {
          std::string truncName(name.substr(0, name.length() - 3));
          this->_nameToVertexProgram.emplace(truncName, ShaderProgram(std::ifstream(folderPath + name), GL_VERTEX_SHADER));
        } else if (name.rfind(".fs") == name.length() - 3) {
          std::string truncName(name.substr(0, name.length() - 3));
          this->_nameToFragProgram.emplace(truncName, ShaderProgram(std::ifstream(folderPath + name), GL_FRAGMENT_SHADER));
        } else if (name.rfind(".tx") == name.length() - 3) {
          std::string truncName(name.substr(0, name.length() - 3));
          this->_nameToTexture.emplace(truncName, AssetLoader::loadTexture(folderPath + name));
        }
      }
    closedir(dir);
  }
  else
    throw std::exception("Couldn't open asset directory");
}

GLuint xlvl::AssetLoader::loadTexture(const std::string &filePath)
{
  std::ifstream in(filePath);
  char data[38];
  in.read(data, 38);
  int32_t offset = *reinterpret_cast<int32_t *>(data + 10);
  int32_t width = *reinterpret_cast<int32_t *>(data + 18);
  int32_t height = *reinterpret_cast<int32_t *>(data + 22);
  uint16_t depth = *reinterpret_cast<int16_t *>(data + 28);
  uint32_t size = *reinterpret_cast<uint32_t *>(data + 34);
  char *buf = new char[size];
  in.seekg(offset);
  in.read(buf, size);

  GLuint id;
  glGenTextures(1, &id);
  glBindTexture(GL_TEXTURE_2D, id);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, buf);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
  delete[] buf;
  return id;
}