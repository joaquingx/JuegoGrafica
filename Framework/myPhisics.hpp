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
  glm::vec3 vel;
  Solid(T * solidArt , glm::mat4 scaleMatrix ,  glm::mat4 rotationMatrix , glm::mat4 traslationMatrix , float solidSize, glm::vec3 vel );
  Solid(T * solidArt , glm::mat4 modelMatrix , float solidSize);
  float getX();
  float getY();
  float getZ();
  glm::vec3 getPos();
  void setModelMatrix();
  void setTraslationMatrix(glm::mat4 traslationMatrix);
  void setRotationMatrix(glm::mat4 rotationMatrix);
  void setVel(glm::vec3 vel);
  void moveSolid();
  void setScaleMatrix(glm::mat4 scaleMatrix);
  void rotateNigga();
};

#endif
