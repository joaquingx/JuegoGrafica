// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
// Include GLEW
#include <GL/glew.h>
// Include GLFW
#include <glfw3.h>
// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;
#include "Framework/myShaders.hpp"
#include "Framework/myConfiguration.hpp"
// #include "Framework/myShapes.hpp"
#include "Framework/myControl.hpp"
#include "Framework/myObjectLoader.hpp"
#include "Framework/myTexture.hpp"
#include "Resources/verticesArt.cpp"
#include "Framework/myArt.hpp"

GLFWwindow * window;
GLuint VertexArrayID;

// GLfloat verticesTriangle[9] = {
//   -1.0f,0.0f, -1.0f,
//   1.0f,0.0f, -1.0f,
//   -1.0f,0.0f,  1.0f
// };

GLfloat verticesTriangle[] = {
  -1.0f, -1.0f, 0.0f,
  1.0f, -1.0f, 0.0f,
  -1.0f,  1.0f, 0.0f,
};

// GLfloat verticesPlane[18] = {
//   -5.0f, -5.0f, 0.0f,
//   5.0f, -5.0f, 0.0f,
//   -5.0f,  5.0f, 0.0f,
//   -5.0f,  5.0f, 0.0f,
//   5.0f,  -5.0f, 0.0f,
//   5.0f,  5.0f, 0.0f
// };

GLfloat verticesPlane[18] = {
  -1.0f, -1.0f, 0.0f,
  1.0f, -1.0f, 0.0f,
  -1.0f,  1.0f, 0.0f,
  -1.0f,  1.0f, 0.0f,
  1.0f,  -1.0f, 0.0f,
  1.0f,  1.0f, 0.0f
};

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

int main( void )
{
  init("Trabajo Final", 1024 , 768 ,window,VertexArrayID);
  // Create and compile our GLSL program from the shaders
  GLuint programID = LoadShaders( "../Resources/GameVertexShader.vertexshader", "../Resources/GameFragmentShader.fragmentshader" );
  GLuint simpleProgramID = LoadShaders( "../Resources/TransformVertexShader.vertexshader", "../Resources/ColorFragmentShader.fragmentshader" );
  // GLuint programID = LoadShaders( "../Resources/LightVertexShader.vertexshader", "../Resources/LightFragmentShader.fragmentshader" );
  // Get a handle for our "MVP" uniform
  GLuint MatrixID = glGetUniformLocation(programID, "MVP");
  GLuint ViewMatrixID = glGetUniformLocation(programID, "V");
  GLuint ModelMatrixID = glGetUniformLocation(programID, "M");

  // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
  glm::mat4 Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
  // Or, for an ortho camera :
  //glm::mat4 Projection = glm::ortho(-10.0f,10.0f,-10.0f,10.0f,0.0f,100.0f); // In world coordinates

  // Camera matrix
  glm::mat4 View       = glm::lookAt(
                                     glm::vec3(0,5,10), // Camera is at (4,3,3), in World Space
                                     glm::vec3(0,0,0), // and looks at the origin
                                     glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
                                     );
  // Model matrix : an identity matrix (model will be at the origin)
  glm::mat4 Modelo      = glm::mat4(1.0f);

  glm::mat4 Scale = glm::scale(glm::mat4(1.0f),vec3(4.5f,1.0f,4.5f));
  glm::mat4 ScaleMini = glm::scale(glm::mat4(1.0f),vec3(0.4f));
  // Our ModelViewProjection : multiplication of our 3 matrices
  glm::mat4 MVP        = Projection * View * Scale * Modelo; // Remember, matrix multiplication is the other way around
  glm::mat4 MVPAUX     = Projection * View * Scale * Modelo; // Remember, matrix multiplication is the other way around
  glm::mat4 rotameLentito = glm::rotate(glm::mat4(1.0f),3.2f,glm::vec3(0,1,0));
  glm::mat4 Traslacion = glm::translate(glm::mat4(1.0f),glm::vec3(0.0f,3.0f,4.0f));

  srand(time(NULL));
  // int myTime = rand() % 10000;

  char  resObj[50],resTexture[50];
  strcpy(resObj,"../Resources/suzanne.obj");// ya que es inseguro :'(
  strcpy(resTexture,"../Resources/uvmap.DDS");
  Model< vector< glm::vec3 > , vector< glm::vec2 > > Susana(resObj,resTexture);
  Shape<GLfloat * > Cubo(432,verticesCube);  // Get a handle for our "myTextureSampler" uniform
  Shape<GLfloat * > Plano(18*4,verticesPlane);
  Shape<GLfloat * > Triangulo(9*4,verticesTriangle);
  // cout << Cubo.myArt[0] << "\n";
  //cout << sizeof(verticesCube) << "\n";
  GLuint TextureID  = glGetUniformLocation(programID, "myTextureSampler");

  // Get a handle for our "LightPosition" uniform
  glUseProgram(programID);
  GLuint LightID = glGetUniformLocation(programID, "LightPosition_worldspace");

  glUseProgram(programID);
  GLuint RandomID = glGetUniformLocation(programID, "Randomness");
  float myTime = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
  glm::mat4 Movimiento = glm::mat4(1.0f);
  do{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glUseProgram(simpleProgramID);
    MVP = MVPAUX;
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &Modelo[0][0]);
    glUniformMatrix4fv(ViewMatrixID, 1, GL_FALSE, &View[0][0]);
    glUniform1f(RandomID,myTime);
    glm::vec3 lightPos = glm::vec3(4,4,4);
    glUniform3f(LightID, lightPos.x, lightPos.y, lightPos.z);
    activateAttribs(3);
    Cubo.bindBuffer(0,3,1,36);
    glUseProgram(programID);
    // glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &Modelo[0][0]);
    glUniformMatrix4fv(ViewMatrixID, 1, GL_FALSE, &View[0][0]);
    moveShape();
    glm::mat4 Rotacion = getRotationMatrix();
    glm::vec3 Movimiento = getTranslateMatrix();
    //glm::mat4 Rotacion = glm::mat4(1.0f);
    Modelo = glm::translate(Modelo , Movimiento);
    // Modelo = translate()
    MVP = Projection * View * Modelo * Traslacion *  Rotacion * ScaleMini; // * Rotacion ;
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    //Triangulo.bindBuffer(0,3,1,3);
    Susana.bindModel(0,TextureID,0,1,2);
    //Plano.bindBuffer(0,3,1,6);

    deactivateAttribs(3);

    // Swap buffers
    glfwSwapBuffers(window);
    glfwPollEvents();

  } // Check if the ESC key was pressed or the window was closed
  while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
         glfwWindowShouldClose(window) == 0 );


  glDeleteProgram(programID);
  glDeleteVertexArrays(1, &VertexArrayID);

  // Close OpenGL window and terminate GLFW
  glfwTerminate();

  return 0;
}
