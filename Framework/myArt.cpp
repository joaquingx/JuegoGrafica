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
Art<T>::Art(){}


template<class T>
Art<T>::~Art(){
  glDeleteBuffers(1, &this->vertexBuffer);
}

template<class T>
void Art<T>::bindArt(){
  glGenBuffers(1,&(this->vertexBuffer));
  glBindBuffer(GL_ARRAY_BUFFER,this->vertexBuffer);
  glBufferData(GL_ARRAY_BUFFER,this->mySize,&(this->myArt[0]), GL_STATIC_DRAW);
}

template<class T>
void Art<T>::bindArt(int algo){
  glGenBuffers(1,&(this->vertexBuffer));
  glBindBuffer(GL_ARRAY_BUFFER,this->vertexBuffer);
  glBufferData(GL_ARRAY_BUFFER,this->mySize,this->myArt, GL_STATIC_DRAW);
}

template<class T>
void Art<T>::bindBuffer(int layout,int theSize, bool toDraw, int nTriangles){
  glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer);
  // cout << GL_ARRAY_BUFFER << " de shapes\n";
  glVertexAttribPointer(
                        layout,                  // attribute. No particular reason for 0, but must match the layout in the shader.
                        theSize,                  // size
                        GL_FLOAT,           // type
                        GL_FALSE,           // normalized?
                        0,                  // stride
                        (void*)0            // array buffer offset
                        );
  if(toDraw)
    {
      // cout << "AFADSASDAS\n";
      glDrawArrays(GL_TRIANGLES, 0, nTriangles);
    }
}


template<class T>
Shape<T>::Shape(int mySize, T myShape){
  this->mySize = mySize;
  this->myArt = myShape;
  this->bindArt();
}

template<class T>
Shape<T>::~Shape(){
}

template<class T>
Texture<T>::Texture(char * path, int mySize, T  myTexture){
  // Load the texture
  this->myIDTexture = loadDDS(path);
  this->myArt = myTexture;
  this->mySize = mySize;
  this->bindArt();
}

template<class T>
void Texture<T>::bindTexture(int TextureID, int identifier,int layout, int theSize){
  // Bind our texture in Texture Unit 0
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, this->myIDTexture);
  // Set our "myTextureSampler" sampler to user Texture Unit 0
  glUniform1i(TextureID, identifier);
  this->bindBuffer(layout,theSize,0,0);
}

template<class T>
Texture<T>::~Texture(){
  glDeleteTextures(1, &this->myIDTexture);
}


template<class T,class T2>
Model<T,T2>::Model(char * path,char * pathTexture){
  std::vector<glm::vec3> vertices;
  std::vector<glm::vec2> uvs;
  std::vector<glm::vec3> normals;
  bool myModel = loadOBJ(path, vertices, uvs, normals);
  this->myVertices = new Shape<T>(vertices.size()*sizeof(glm::vec3) , vertices);
  this->myNormal = new Shape<T>(normals.size()*sizeof(glm::vec3),normals);
  this->myUvs = new Texture<T2>(pathTexture,uvs.size() * sizeof(glm::vec2) , uvs);
}
template<class T , class T2>
Model<T,T2>::~Model(){
  delete myVertices;
  delete myNormal;
  delete myUvs;
}

template<class T, class T2>
void Model<T,T2>::bindModel(int identifier, int TextureID, int layoutVertice,int layoutTexture, int layoutNormal){
  myUvs->bindTexture(TextureID,identifier,layoutTexture,2);
  myNormal->bindBuffer(layoutNormal,3,0,myNormal->myArt.size());
  myVertices->bindBuffer(layoutVertice,3,1,myVertices->myArt.size());
}


template class Model< vector< glm::vec3 > , vector< glm::vec2 > >;
template class Shape< vector<glm::vec3> >;
template class Texture< vector<glm::vec2> >;
template class Shape< GLfloat * >;
template class Art<GLfloat * >;
template class Texture<GLfloat * >;

