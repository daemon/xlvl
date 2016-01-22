#include <fstream>
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
        }
      }
    closedir(dir);
  }
  else
    throw std::exception("Couldn't open asset directory");
}