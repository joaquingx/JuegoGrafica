#ifndef MYPHISICS_HPP
#define MYPHISICS_HPP
#include <iostream>
#include <string.h>
#include <GL/glew.h>
// Include GLFW
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "myArt.hpp"
#include "myObjectLoader.hpp"
#include "myTexture.hpp"
using namespace std;

template<class T>
class Solid{
public:
  T * solidArt;
  glm::mat4 modelMatrix, scaleMatrix , rotationMatrix, traslationMatrix;
  float solidSize;
  Solid(T * solidArt , glm::mat4 scaleMatrix ,  glm::mat4 rotationMatrix , glm::mat4 traslationMatrix , float solidSize)
  {
    this->solidArt = solidArt;
    this->modelMatrix = traslationMatrix * rotationMatrix * scaleMatrix ;
    this->scaleMatrix = scaleMatrix;
    this->rotationMatrix = rotationMatrix;
    this->traslationMatrix = traslationMatrix;
    this->solidSize = solidSize;
  }
  Solid(T * solidArt , glm::mat4 modelMatrix , float solidSize)
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

  void setModelMatrix()
  {
    this->modelMatrix = traslationMatrix * rotationMatrix * scaleMatrix;
  }
  void setTraslationMatrix(glm::mat4 traslationMatrix)
  {
    this->traslationMatrix = traslationMatrix;
    setModelMatrix();
  }

  void setRotationMatrix(glm::mat4 rotationMatrix)
  {
    this->rotationMatrix = rotationMatrix;
    setModelMatrix();
  }

  void setScaleMatrix(glm::mat4 scaleMatrix)
  {
    this->scaleMatrix = scaleMatrix;
    setModelMatrix();
  }

};

template<class T>
class Bullet : public Solid<T> {
public:
  pair< int,int > dir;
  Bullet(T * solidArt , glm::mat4 scaleMatrix ,  glm::mat4 rotationMatrix , glm::mat4 traslationMatrix , float solidSize, pair<int ,int > dir ):
    Solid<T>(solidArt ,scaleMatrix , rotationMatrix , traslationMatrix , solidSize)
  {
    this->dir = dir;
  }
};


#endif
