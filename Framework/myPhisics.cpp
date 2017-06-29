#include <iostream>
#include <string.h>
#include <GL/glew.h>
// Include GLFW
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>

#include "myArt.hpp"
#include "myObjectLoader.hpp"
#include "myTexture.hpp"
#include "myPhisics.hpp"
using namespace std;

template<class T>
Solid<T>::Solid(T * solidArt , glm::mat4 scaleMatrix ,  glm::mat4 rotationMatrix , glm::mat4 traslationMatrix , float solidSize, glm::vec3 vel )
{
  this->solidArt = solidArt;
  this->modelMatrix = traslationMatrix * rotationMatrix * scaleMatrix ;
  this->scaleMatrix = scaleMatrix;
  this->rotationMatrix = rotationMatrix;
  this->traslationMatrix = traslationMatrix;
  this->solidSize = solidSize;
  this->vel = vel;
}

template<class T>
Solid<T>::Solid(T * solidArt , glm::mat4 modelMatrix , float solidSize)
{
  this->solidArt = solidArt;
  this->modelMatrix = modelMatrix ;
  this->solidSize = solidSize;
}

template<class T>
float Solid<T>::getX()
{
  return this->modelMatrix[3][0];
}


template<class T>
float Solid<T>::getY()
{
  return this->modelMatrix[3][1];
}


template<class T>
float Solid<T>::getZ()
{
  return this->modelMatrix[3][2];
}


template<class T>
glm::vec3 Solid<T>::getPos()
{
  return glm::vec3(getX(),getY(),getZ());
}


template<class T>
void Solid<T>::setModelMatrix()
{
  this->modelMatrix = traslationMatrix * rotationMatrix * scaleMatrix;
}


template<class T>
void Solid<T>::setTraslationMatrix(glm::mat4 traslationMatrix)
{
  this->traslationMatrix = traslationMatrix;
  setModelMatrix();
}


template<class T>
void Solid<T>::setRotationMatrix(glm::mat4 rotationMatrix)
{
  this->rotationMatrix = rotationMatrix;
  setModelMatrix();
}

template<class T>
void Solid<T>::setVel(glm::vec3 vel)
{
  this->vel = vel;
}

template<class T>
void Solid<T>::moveSolid()
{
  setTraslationMatrix(glm::translate(traslationMatrix,vel));
}

template<class T>
void Solid<T>::setScaleMatrix(glm::mat4 scaleMatrix)
{
  this->scaleMatrix = scaleMatrix;
  setModelMatrix();
}

template<class T>
void Solid<T>::rotateNigga()
{
  glm::vec3 nvel = glm::vec3(vel.x,0,vel.z);
  glm::mat4 rotation = glm::rotate(rotationMatrix, 0.01f, glm::normalize(nvel));
  setRotationMatrix(rotation);
}




template class Solid<Shape<float*> >;
