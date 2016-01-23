#pragma once

namespace xlvl 
{

class DrawingObject
{
public:
  void draw() { this->_draw(); }  
private:
  virtual void _draw() = 0;
};

}