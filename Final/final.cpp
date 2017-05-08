// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <list>
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
#include "Framework/myPhisics.cpp"

const int TAMCUBE = 432, N = 3, M = 3 ;


GLFWwindow * window;
GLuint VertexArrayID;


// class cuarto


int main( void )
{
  //Aux Varibales
  int cnt = 0 ;
  init("Trabajo Final", 1500 , 1200 ,window,VertexArrayID);
  // Create and compile our GLSL program from the shaders
  GLuint programID = LoadShaders( "../Resources/GameVertexShader.vertexshader", "../Resources/GameFragmentShader.fragmentshader" );

  GLuint MatrixID = glGetUniformLocation(programID, "MVP");
  GLuint ViewMatrixID = glGetUniformLocation(programID, "V");
  GLuint ModelMatrixID = glGetUniformLocation(programID, "M");

  glm::mat4 Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);

  glm::mat4 View       = glm::lookAt(
                                     glm::vec3(0,10,10), // Camera is at (4,3,3), in World Space
                                     glm::vec3(0,0,0), // and looks at the origin
                                     glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
                                     );
  // View = glm::translate(View,glm::vec3(-15.0f,0.0f,-10.0f));

  glm::mat4 MVP;
  // Model matrix : an identity matrix (model will be at the origin)
  glm::mat4 Modelo     = glm::mat4(1.0f);

  glm::mat4 ScaleLarge = glm::scale(glm::mat4(1.0f),vec3(1.0f,1.0f,4.5f));
  glm::mat4 ScaleWidth = glm::scale(glm::mat4(1.0f),vec3(4.5f,1.0f,1.0f));
  // glm::mat4 Scale = glm::mat4(1.0f);
  glm::mat4 ScaleMini = glm::scale(glm::mat4(1.0f),vec3(0.4f));
  // Our ModelViewProjection : multiplication of our 3 matrices
  // glm::mat4 MVP        = Projection * View * Scale * Modelo; // Remember, matrix multiplication is the other way around
  // glm::mat4 MVPAUX     = Projection * View * Scale * Modelo; // Remember, matrix multiplication is the other way around
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
  // Solid<GLfloat * > ;
  // Solids Shapes.

  // Solid< Shape<GLfloat *> >  solidPlane(new Shape<GLfloat * >(TAMCUBE,verticesCube),glm::mat4(1.0f),10.0f);
  Solid< Shape<GLfloat *> >  solidPlane(new Shape<GLfloat * >(TAMCUBE,verticesCube),glm::scale(glm::mat4(1.0f),vec3(4.5f,1.0f,4.5f))
                                        ,glm::mat4(1.0f),glm::mat4(1.0f), 10.0f);

  list < Bullet< Shape<GLfloat *> > *  >  solidBullets;  

  pair<int,int> pos = {0,0};
  pair<int, int> actdir= {0,0};
  int newState=GLFW_RELEASE,oldState=GLFW_RELEASE;
  bool escenario[100][100];
  for(int i = 0 ;i < N ; ++i)
    for(int j = 0 ; j < M ; ++j)
      {
        if(rand() & 2)
          escenario[i][j] = 1;
        else
          escenario[i][j] = 0;
      }
  escenario[0][0] = 1;

  for(int i = 0 ;i < N ; ++i)
    {
      for(int j = 0 ; j < M ; ++j)
        cout << escenario[i][j] << " ";
      cout << "\n";
    }
  glm::vec3 xMov,zMov;
  xMov = glm::vec3(9.0f,0.0f,0.0f);
  zMov = glm::vec3(0.0f,0.0f,9.0f);
  glm::mat4 firstTraslationMatrix = glm::mat4(1.0f);

  // solidCube.solidArt = new Shape(TAMCUBE,verticesCube);

  //Solids Models.
  Solid< Model< vector< glm::vec3 > , vector< glm::vec2 > > > solidSuzane( new Model< vector< glm::vec3 >, vector< glm::vec2 > >(resObj,resTexture) ,
                                                                           glm::scale(glm::mat4(1.0f),vec3(0.4f)),glm::mat4(1.0f),glm::translate(glm::mat4(1.0f),glm::vec3(1.0f,2.0f,1.0f)) , 5.0f);
  // Solid< Model< vector< glm::vec3 > , vector< glm::vec2 > > > solidSuzane( new Model< vector< glm::vec3 >, vector< glm::vec2 > >(resObj,resTexture) ,
  //                                                                          glm::mat4(1.0f),glm::mat4(1.0f),glm::mat4(1.0f), 5.0f);
  // solidSuzane.solidArt = new Model(resObj,resTexture);


  Texture<GLfloat * > TexturaRoca(resTexture,sizeof(myUv),myUv);


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

    glm::vec3 lightPos = glm::vec3(4,4,4);
    
    glUniform3f(LightID, lightPos.x, lightPos.y, lightPos.z);

    activateAttribs(3);

    //Drawing Scenario
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &Modelo[0][0]);
    glUniformMatrix4fv(ViewMatrixID, 1, GL_FALSE, &View[0][0]);
    TexturaRoca.bindTexture(TextureID,0,1,2);



    MVP = Projection * View * solidPlane.modelMatrix;
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    solidPlane.solidArt->bindBuffer(0,3,1,36);
    moveShape();
    glm::mat4 modeloAux = glm::translate(solidSuzane.traslationMatrix , getTranslateMatrix());
    if(validatePosition(modeloAux,4.0,-4.0,4.5,-3.3)) // falta valida posiciones
      solidSuzane.setTraslationMatrix(modeloAux);
    else
      solidSuzane.setTraslationMatrix(glm::translate(solidSuzane.traslationMatrix,
                                      changeScenario(modeloAux,pos,escenario, N ,M)));
    solidSuzane.setRotationMatrix(getRotationMatrix());
    actdir = getDirection();
    glUniform1f(forbidden,0);
    MVP = Projection * View * solidSuzane.modelMatrix;
    // glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &Modelo[0][0]);
    glUniformMatrix4fv(ViewMatrixID, 1, GL_FALSE, &View[0][0]);
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    solidSuzane.solidArt->bindModel(0,TextureID,0,1,2);
    // glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    // MVP = Projection * View * Modelo * Traslacion *  Rotacion * ScaleMini; // * Rotacion ;
    if(cnt == 599)    
      {
        cout << "Del Mono\n";
        cout << glm::to_string( solidSuzane.modelMatrix ) << "\n";
        cout << "Del Plano\n";
        cout << glm::to_string( solidPlane.modelMatrix ) << "\n"; 
      }
    // Susana.bindModel(0,TextureID,0,1,// 2);-*

    newState = glfwGetKey(window, GLFW_KEY_SPACE );
    
    if(newState == GLFW_PRESS and oldState == GLFW_RELEASE)
      {
        solidBullets.push_back( new Bullet< Shape<GLfloat * > >(new Shape<GLfloat * >(TAMCUBE,verticesCube) , glm::scale(glm::mat4(1.0f),vec3(0.08f))
                                ,glm::mat4(1.0f), solidSuzane.traslationMatrix  , 10.0f, actdir ) );
      }
    oldState = newState;
    //Drawing Bullets
    for(auto it = solidBullets.begin() ; it != solidBullets.end() ; ++it)
      {
        // cout << (*it)->dir.first << " " << (*it)->dir.second << "\n";
        (*it)->setTraslationMatrix( glm::translate( (*it)->traslationMatrix, glm::vec3( (*it)->dir.first * 0.1, 0.0f , (*it)->dir.second * 0.1 ) ) );
        MVP =  Projection * View * (*it)->modelMatrix;
        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
        (*it)->solidArt->bindBuffer(0,3,1,36);
      }
    
    deactivateAttribs(3);
    cnt = (cnt + 1)%600;
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
