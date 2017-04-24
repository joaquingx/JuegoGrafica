#include <iostream>
#include <string.h>
#include <GL/glew.h>
// Include GLFW
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "myShapes.hpp"
using namespace std;


GLfloat colorCube[] = {
  0.583f,  0.771f,  0.014f,
  0.609f,  0.115f,  0.436f,
  0.327f,  0.483f,  0.844f,
  0.822f,  0.569f,  0.201f,
  0.435f,  0.602f,  0.223f,
  0.310f,  0.747f,  0.185f,
  0.597f,  0.770f,  0.761f,
  0.559f,  0.436f,  0.730f,
  0.359f,  0.583f,  0.152f,
  0.483f,  0.596f,  0.789f,
  0.559f,  0.861f,  0.639f,
  0.195f,  0.548f,  0.859f,
  0.014f,  0.184f,  0.576f,
  0.771f,  0.328f,  0.970f,
  0.406f,  0.615f,  0.116f,
  0.676f,  0.977f,  0.133f,
  0.971f,  0.572f,  0.833f,
  0.140f,  0.616f,  0.489f,
  0.997f,  0.513f,  0.064f,
  0.945f,  0.719f,  0.592f,
  0.543f,  0.021f,  0.978f,
  0.279f,  0.317f,  0.505f,
  0.167f,  0.620f,  0.077f,
  0.347f,  0.857f,  0.137f,
  0.055f,  0.953f,  0.042f,
  0.714f,  0.505f,  0.345f,
  0.783f,  0.290f,  0.734f,
  0.722f,  0.645f,  0.174f,
  0.302f,  0.455f,  0.848f,
  0.225f,  0.587f,  0.040f,
  0.517f,  0.713f,  0.338f,
  0.053f,  0.959f,  0.120f,
  0.393f,  0.621f,  0.362f,
  0.673f,  0.211f,  0.457f,
  0.820f,  0.883f,  0.371f,
  0.982f,  0.099f,  0.879f
};

GLfloat colorCube2[] = {
  1.0f,0.0f,0.0f,
  1.0f,0.0f,0.0f,
  1.0f,0.0f,0.0f,
  1.0f,0.0f,0.0f,
  1.0f,0.0f,0.0f,
  1.0f,0.0f,0.0f,
  1.0f,0.0f,0.0f,
  1.0f,0.0f,0.0f,
  1.0f,0.0f,0.0f,
  1.0f,0.0f,0.0f,
  1.0f,0.0f,0.0f,
  1.0f,0.0f,0.0f,
  1.0f,0.0f,0.0f,
  1.0f,0.0f,0.0f,
  1.0f,0.0f,0.0f,
  1.0f,0.0f,0.0f,
  1.0f,0.0f,0.0f,
  1.0f,0.0f,0.0f,
  1.0f,0.0f,0.0f,
  1.0f,0.0f,0.0f,
  1.0f,0.0f,0.0f,
  1.0f,0.0f,0.0f,
  1.0f,0.0f,0.0f,
  1.0f,0.0f,0.0f,
  1.0f,0.0f,0.0f,
  1.0f,0.0f,0.0f,
  1.0f,0.0f,0.0f,
  1.0f,0.0f,0.0f,
  1.0f,0.0f,0.0f,
  1.0f,0.0f,0.0f,
  1.0f,0.0f,0.0f,
  1.0f,0.0f,0.0f,
  1.0f,0.0f,0.0f,
  1.0f,0.0f,0.0f,
  1.0f,0.0f,0.0f,
  1.0f,0.0f,0.0f
};


//triangle
GLfloat  verticesTriangle[9] = {
  -1.0f, -1.0f, 0.0f,
  1.0f, -1.0f, 0.0f,
  0.0f,  1.0f, 0.0f,
};

// Cube
GLfloat verticesCube[108] = {
  -1.0f,-1.0f,-1.0f,
  -1.0f,-1.0f, 1.0f,
  -1.0f, 1.0f, 1.0f,
  1.0f, 1.0f,-1.0f,
  -1.0f,-1.0f,-1.0f,
  -1.0f, 1.0f,-1.0f,
  1.0f,-1.0f, 1.0f,
  -1.0f,-1.0f,-1.0f,
  1.0f,-1.0f,-1.0f,
  1.0f, 1.0f,-1.0f,
  1.0f,-1.0f,-1.0f,
  -1.0f,-1.0f,-1.0f,
  -1.0f,-1.0f,-1.0f,
  -1.0f, 1.0f, 1.0f,
  -1.0f, 1.0f,-1.0f,
  1.0f,-1.0f, 1.0f,
  -1.0f,-1.0f, 1.0f,
  -1.0f,-1.0f,-1.0f,
  -1.0f, 1.0f, 1.0f,
  -1.0f,-1.0f, 1.0f,
  1.0f,-1.0f, 1.0f,
  1.0f, 1.0f, 1.0f,
  1.0f,-1.0f,-1.0f,
  1.0f, 1.0f,-1.0f,
  1.0f,-1.0f,-1.0f,
  1.0f, 1.0f, 1.0f,
  1.0f,-1.0f, 1.0f,
  1.0f, 1.0f, 1.0f,
  1.0f, 1.0f,-1.0f,
  -1.0f, 1.0f,-1.0f,
  1.0f, 1.0f, 1.0f,
  -1.0f, 1.0f,-1.0f,
  -1.0f, 1.0f, 1.0f,
  1.0f, 1.0f, 1.0f,
  -1.0f, 1.0f, 1.0f,
  1.0f,-1.0f, 1.0f
};

void Shape::bindShape(){
  glGenBuffers(1,&(this->vertexBuffer));
  glBindBuffer(GL_ARRAY_BUFFER,this->vertexBuffer);
  glBufferData(GL_ARRAY_BUFFER,this->mySize,this->myShape, GL_STATIC_DRAW);
}

void Shape::bindBuffer(int layout){
  glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer);
  // cout << GL_ARRAY_BUFFER << " de shapes\n";
  glVertexAttribPointer(
                        layout,                  // attribute. No particular reason for 0, but must match the layout in the shader.
                        3,                  // size
                        GL_FLOAT,           // type
                        GL_FALSE,           // normalized?
                        0,                  // stride
                        (void*)0            // array buffer offset
                        );
  if(!layout) glDrawArrays(GL_TRIANGLES, 0, (this->mySize/(3*4))); // 12*3 indices starting at 0 -> 12 triangles
  // xD
}

Shape::Shape(){}

Shape::~Shape(){
  glDeleteBuffers(1, &this->vertexBuffer);
}


Triangle::Triangle(){
  this->mySize = 9*4;
  // this->myShape = verticesTriangle;
  createShape();
  bindShape();
}

void Triangle::createShape(){
  this->myShape = verticesTriangle;
}


Cube::Cube(){
  this->mySize = 108 * 4;
  createShape();
  bindShape();
}

void Cube::createShape(){
  this->myShape = verticesCube;
}


void CubeColor::createShape(int who){
  if(who)
    this->myShape = colorCube;
  else
    this->myShape = colorCube2;
}

CubeColor::CubeColor(int who){
  this->mySize = 108 * 4;
  createShape(who);
  bindShape();
}
