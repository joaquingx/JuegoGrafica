// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <list>
#include <time.h>
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
#include "Framework/myControl.hpp"
#include "Framework/myObjectLoader.hpp"
#include "Framework/myTexture.hpp"
#include "Resources/verticesArt.cpp"
#include "Framework/myArt.hpp"
#include "Framework/myPhisics.hpp"
#include "Framework/myMap.cpp"
#include "Framework/boids.cpp"

typedef vector < Solid< Shape<GLfloat *> >  * >  bandada;
const int N = 10;
const int TAMCUBE = 432, TAMTRIANGLE = 36;

GLFWwindow * window;
GLuint VertexArrayID;


// class cuarto


int main( void )
{
  init("Trabajo Final", 1500 , 1200 ,window,VertexArrayID);
  // Create and compile our GLSL program from the shaders
  GLuint programID = LoadShaders( "../Resources/GameVertexShader.vertexshader", "../Resources/GameFragmentShader.fragmentshader" );

  GLuint MatrixID = glGetUniformLocation(programID, "MVP");
  GLuint ViewMatrixID = glGetUniformLocation(programID, "V");
  GLuint ModelMatrixID = glGetUniformLocation(programID, "M");
  GLuint LightID = glGetUniformLocation(programID, "LightPosition_worldspace");


  glm::mat4 Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);

  glm::mat4 View       = glm::lookAt(
                                     glm::vec3(0,20,20), // Camera is at (4,3,3), in World Space
                                     glm::vec3(0,0,0), // and looks at the origin
                                     glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
                                     );
  // View = glm::translate(View,glm::vec3(-15.0f,0.0f,-10.0f));

  glm::mat4 MVP;
  // Model matrix : an identity matrix (model will be at the origin)
  glm::mat4 Modelo   = glm::mat4(1.0f);

  //Boids Creation
  bandada myBoids(N);
  int maxArea = 3,maxVel=100,myX,myY,myZ;
  for(int i = 0 ;i < N ; ++i)
    {
      myX = rand() % maxArea;
      myY = rand() % maxArea;
      myZ = rand() % maxArea;
      float velX = float(rand() % maxVel)/1000;
      float velY = float(rand() % maxVel)/1000;
      float velZ = float(rand() % maxVel)/1000;
      myBoids[i] = new Solid< Shape<GLfloat *> >(new Shape<GLfloat * >(TAMTRIANGLE,verticesTriangle),glm::scale(glm::mat4(1.0f),vec3(0.3f))
                                                 ,glm::mat4(1.0f),glm::translate(glm::mat4(1.0f),glm::vec3(myX,myY,myZ)), 10.0f, glm::vec3(velX,velY,velZ));
    }
  // myBoids[0] =new Solid< Shape<GLfloat *> >(new Shape<GLfloat * >(TAMTRIANGLE,verticesTriangle),glm::scale(glm::mat4(1.0f),vec3(0.3f))
  //                                           ,glm::mat4(1.0f),glm::translate(glm::mat4(1.0f),glm::vec3(0.0f,0.0f,0.0f)), 10.0f, glm::vec3(0.0f,0.0f,0.0f) ) ;
  //Boids Creation

  do{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(programID);

    glm::vec3 lightPos = glm::vec3(4,4,4);

    glUniform3f(LightID, lightPos.x, lightPos.y, lightPos.z);


    activateAttribs(3);

    computeMatrices();
    View = getViewMatrix();


    //Drawing Scenario
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &Modelo[0][0]);
    glUniformMatrix4fv(ViewMatrixID, 1, GL_FALSE, &View[0][0]);


    // MVP = Projection * View *  myBoids[0]->modelMatrix ;
    // glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    // myBoids[0]->solidArt->bindBuffer(0,3,1,36);

    for(int i = 0 ; i < N ; ++i)
      {
        glm::vec3 forces =
          (cohesion(myBoids,i) +
          separation(myBoids,i) +
           alignment(myBoids,i) )
          * 0.05f
          +  collision(myBoids,i)
          ;
        myBoids[i]->vel += forces;
        myBoids[i]->vel = limitVelocity(myBoids[i]->vel);
        cout << glm::to_string(myBoids[i]->getPos()) << "\n";
        myBoids[i]->moveSolid();
        // myBoids[i]->rotateNigga();
        MVP = Projection * View *  myBoids[i]->modelMatrix ;
        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
        myBoids[i]->solidArt->bindBuffer(0,3,1,36);
      }


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
