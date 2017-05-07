#ifndef MYPHISICS_HPP
#define MYPHISICS_HPP
#include <vector>
template<class T>
class Solid{
public:
  Art<T> * solidArt;
  glm::mat4 modelMatrix;
  float solidSize;
  Solid(Art<T> * solidArt , glm::mat4 scaleMatrix ,  glm::mat4 rotationMatrix , glm::mat4 traslationMatrix , float solidSize)
  {
    this->solidArt = solidArt;
    this->modelMatrix = traslationMatrix * rotationMatrix * scaleMatrix ;
    this->solidSize = solidSize;
  }

  Solid(Art<T> * solidArt , glm::mat4 modelMatrix , float solidSize)
  {
    this->solidArt = solidArt;
    this->modelMatrix = modelMatrix ;
    this->solidSize = solidSize;
  }
  float getX()
  {
    return this->Model[3][0];
  }
  float getY()
  {
    return this->Model[3][1];
  }

  float getZ()
  {
    return this->Model[3][2];
  }
};


#endif MYPHISICS_HPP
