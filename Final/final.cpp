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
#include "glm/ext.hpp"
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

int main( void )
{
  //Aux Varibales
  int cnt = 0 ;
  init("Trabajo Final", 1024 , 768 ,window,VertexArrayID);
  // Create and compile our GLSL program from the shaders
  GLuint programID = LoadShaders( "../Resources/GameVertexShader.vertexshader", "../Resources/GameFragmentShader.fragmentshader" );
  //GLuint simpleProgramID = LoadShaders( "../Resources/TransformVertexShader.vertexshader", "../Resources/ColorFragmentShader.fragmentshader" );
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
  glm::mat4 ScaleLarge = glm::scale(glm::mat4(1.0f),vec3(1.0f,1.0f,4.5f));
  glm::mat4 ScaleWidth = glm::scale(glm::mat4(1.0f),vec3(4.5f,1.0f,1.0f));
  // glm::mat4 Scale = glm::mat4(1.0f);
  glm::mat4 ScaleMini = glm::scale(glm::mat4(1.0f),vec3(0.4f));
  // Our ModelViewProjection : multiplication of our 3 matrices
  glm::mat4 MVP        = Projection * View * Scale * Modelo; // Remember, matrix multiplication is the other way around
  glm::mat4 MVPAUX     = Projection * View * Scale * Modelo; // Remember, matrix multiplication is the other way around
  glm::mat4 rotameLentito = glm::rotate(glm::mat4(1.0f),3.2f,glm::vec3(0,1,0));
  glm::mat4 Traslacion = glm::translate(glm::mat4(1.0f),glm::vec3(0.0f,3.0f,4.0f));

  srand(time(NULL));
  // int myTime = rand() % 10000;

  char  resObj[50],resTexture[50], resTexturaRoca[50];
  strcpy(resObj,"../Resources/suzanne.obj");// ya se que es inseguro :'(
  strcpy(resTexture,"../Resources/uvmap.DDS");// ya se que es inseguro :'(
  //strcpy(resTexturaRoca,"../Resources/textureroca.DDS");// ya se que es inseguro :'(
  // strcpy(resTexturaRoca,"../Resources/uvtemplate.DDS");// ya se que es inseguro :'(


  // GLuint TextureRocaID  = glGetUniformLocation(programID, "myTextureSampler");

  //Declaring ShapesTexturesModels
  Model< vector< glm::vec3 > , vector< glm::vec2 > > Susana(resObj,resTexture);
  Texture<GLfloat * > TexturaRoca(resTexture,sizeof(myUv),myUv);
  Shape<GLfloat * > Cubo(432,verticesCube);  // Get a handle for our "myTextureSampler" uniform
  Shape<GLfloat * > Plano(18*4,verticesPlane);
  Shape<GLfloat * > Triangulo(9*4,verticesTriangle);

  // Get a handle for our "TEXTURE" uniform
  GLuint TextureID  = glGetUniformLocation(programID, "myTextureSampler");

  // Get a handle for our "LightPosition" uniform
  glUseProgram(programID);
  GLuint LightID = glGetUniformLocation(programID, "LightPosition_worldspace");
  GLuint forbidden = glGetUniformLocation(programID, "forbidden");
  do{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(programID);
    glUniform1f(forbidden,1);
    MVP = MVPAUX;
    glm::vec3 lightPos = glm::vec3(4,4,4);
    glUniform3f(LightID, lightPos.x, lightPos.y, lightPos.z);

    activateAttribs(3);
    //Drawing Scenario
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &Modelo[0][0]);
    glUniformMatrix4fv(ViewMatrixID, 1, GL_FALSE, &View[0][0]);
    TexturaRoca.bindTexture(TextureID,0,1,2);
    Cubo.bindBuffer(0,3,1,36);

    MVP = Projection * View * glm::translate(glm::mat4(0.1f), glm::vec3(5.5f, 2.0f, 0.0f)) * ScaleLarge;
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glUniform1f(forbidden,1);				   
    Cubo.bindBuffer(0,3,1,36);

    MVP = Projection * View * glm::translate(glm::mat4(0.1f), glm::vec3(-5.5f, 2.0f, 0.0f)) * ScaleLarge;
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glUniform1f(forbidden,1);				   
    Cubo.bindBuffer(0,3,1,36);

    MVP = Projection * View * glm::translate(glm::mat4(0.1f), glm::vec3(0.0f , 2.0f, -5.5f)) * ScaleWidth;
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glUniform1f(forbidden,1);				   
    Cubo.bindBuffer(0,3,1,36);

    glUniform1f(forbidden,0);
    //Drawing SUSANA
    moveShape();
    glm::mat4 Rotacion = getRotationMatrix();
    glm::vec3 Movimiento = getTranslateMatrix();
    glm::mat4 ModeloAux = glm::translate(Modelo , Movimiento);
    if(validatePosition(ModeloAux,2.5,-2.5,2.5,-2.5))
      Modelo = ModeloAux;
    MVP = Projection * View * Modelo * Traslacion *  Rotacion * ScaleMini; // * Rotacion ;
    if(cnt == 99)    cout << glm::to_string(Modelo) << "\n";
    glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &Modelo[0][0]);
    glUniformMatrix4fv(ViewMatrixID, 1, GL_FALSE, &View[0][0]);
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    Susana.bindModel(0,TextureID,0,1,2);

    deactivateAttribs(3);
    cnt = (cnt + 1)%100;
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
