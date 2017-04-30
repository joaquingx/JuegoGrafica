#include <glfw3.h>
extern GLFWwindow* window;
// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

#include "myControl.hpp"

glm::mat4 ViewMatrix;
glm::mat4 ProjectionMatrix;
glm::mat4 RotationMatrix;
glm::vec3 TranslateVector;
// glm::mat4 ModelMatrix;

glm::mat4 getViewMatrix(){
  return ViewMatrix;
}
glm::mat4 getProjectionMatrix(){
  return ProjectionMatrix;
}

glm::vec3 getTranslateMatrix(){
  return TranslateVector;
}
glm::mat4 getRotationMatrix(){
  return RotationMatrix;
}


glm::vec3 position = glm::vec3( 0, 0, 5 );
float horizontalAngle = 3.14f;
float verticalAngle = 0.0f;
float initialFoV = 45.0f;

float speed = 1.0f; // 3 units / second
float mouseSpeed = 0.005f;



void computeMatrices(){

  static double lastTime = glfwGetTime();

  double currentTime = glfwGetTime();
  float delta = float(currentTime - lastTime);

  double xpos, ypos;

  glfwGetCursorPos(window, &xpos, &ypos);
  glfwSetCursorPos(window, 1024/2, 768/2);

  horizontalAngle += mouseSpeed * float(1024/2 - xpos );
  verticalAngle   += mouseSpeed * float( 768/2 - ypos );

  glm::vec3 direction(
                      cos(verticalAngle) * sin(horizontalAngle),
                      sin(verticalAngle),
                      cos(verticalAngle) * cos(horizontalAngle)
                      );

  glm::vec3 right = glm::vec3(
                              sin(horizontalAngle - 3.14f/2.0f),
                              0,
                              cos(horizontalAngle - 3.14f/2.0f)
                              );

  glm::vec3 up = glm::cross( right, direction );

  if (glfwGetKey( window, GLFW_KEY_UP ) == GLFW_PRESS){
    position += direction * delta * speed;
  }
  if (glfwGetKey( window, GLFW_KEY_DOWN ) == GLFW_PRESS){
    position -= direction * delta * speed;
  }
  if (glfwGetKey( window, GLFW_KEY_RIGHT ) == GLFW_PRESS){
    position += right * delta * speed;
  }
  if (glfwGetKey( window, GLFW_KEY_LEFT ) == GLFW_PRESS){
    position -= right * delta * speed;
  }

  float FoV = initialFoV;// - 5 * glfwGetMouseWheel();

  // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
  ProjectionMatrix = glm::perspective(FoV, 4.0f / 3.0f, 0.1f, 100.0f);
  // Camera matrix
  ViewMatrix       = glm::lookAt(
                                 position,
                                 position+direction,
                                 up
                                 );

  lastTime = currentTime;
}

void moveShape(){
  // RotationMatrix = glm::mat4(1.0f);
  TranslateVector = glm::vec3(0.0f);
  glm::vec3 toUp = glm::vec3(0.0f,0.0f,0.1f);
  glm::vec3 toDown = glm::vec3(0.0f,0.0f,-0.1f);
  glm::vec3 toLeft = glm::vec3(-0.1f,0.0f,0.0f);
  glm::vec3 toRight = glm::vec3(0.1f,0.0f,0.0f);
  if (glfwGetKey( window, GLFW_KEY_UP ) == GLFW_PRESS){
    TranslateVector =  toDown;
    RotationMatrix = glm::rotate(glm::mat4(1.0f),3.2f,glm::vec3(0,1,0));
  }
  if (glfwGetKey( window, GLFW_KEY_DOWN ) == GLFW_PRESS){
    TranslateVector =  toUp;
    RotationMatrix = glm::rotate(glm::mat4(1.0f),0.0f,glm::vec3(0,1,0));
  }
  if (glfwGetKey( window, GLFW_KEY_RIGHT ) == GLFW_PRESS){
    TranslateVector =  toRight;
    RotationMatrix = glm::rotate(glm::mat4(1.0f),1.5f,glm::vec3(0,1,0));
  }
  if (glfwGetKey( window, GLFW_KEY_LEFT ) == GLFW_PRESS){
    TranslateVector =  toLeft;
    RotationMatrix = glm::rotate(glm::mat4(1.0f),4.7f,glm::vec3(0,1,0));
  }
}
