#include <glfw3.h>
extern GLFWwindow* window;
// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;
using namespace std;

#include "myControl.hpp"
#include "myMap.cpp"

glm::mat4 ViewMatrix;
glm::mat4 ProjectionMatrix;
glm::mat4 RotationMatrix;
glm::vec3 TranslateVector;
pair<int , int > direction = {0,1};
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

bool validatePosition(glm::mat4 Modelo, float maxX , float minX , float maxZ, float minZ)
{
  float myX = Modelo[3][0], myZ = Modelo[3][2];
  if(myX > maxX or myX < minX or myZ > maxZ or myZ < minZ)
    return 0;
  return 1;
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
    direction = {0,-1};
  }
  if (glfwGetKey( window, GLFW_KEY_DOWN ) == GLFW_PRESS){
    TranslateVector =  toUp;
    RotationMatrix = glm::rotate(glm::mat4(1.0f),0.0f,glm::vec3(0,1,0));
    direction = {0,1};
  }
  if (glfwGetKey( window, GLFW_KEY_RIGHT ) == GLFW_PRESS){
    TranslateVector =  toRight;
    RotationMatrix = glm::rotate(glm::mat4(1.0f),1.5f,glm::vec3(0,1,0));
    direction = {1,0};
  }
  if (glfwGetKey( window, GLFW_KEY_LEFT ) == GLFW_PRESS){
    TranslateVector =  toLeft;
    RotationMatrix = glm::rotate(glm::mat4(1.0f),4.7f,glm::vec3(0,1,0));
    direction = {-1,0};
  }
}


bool validate(bool ** escenario , pair<int,int> pos, int N , int M )
{
  if(pos.second  < M and pos.second >= 0 and
     pos.first < N and pos.first >= 0 and
     escenario[pos.first][pos.second] == 1)
    return 1;
  return 0;
}

pair<int,int> getDirection()
{
  return direction;
}


glm::vec3 changeScenario( glm::mat4 modeloAux , pair < int , int >  & pos,
                          vector< vector< Nodo *> > escenario , int N , int M, bool & cambio)
{
  cambio = 0;
  if(modeloAux[3][0] >= 4.0)
    {
      if(pos.second + 1 < M and pos.second+1 >= 0  and
         escenario[pos.first][pos.second+1]->mAllowable)
        {
          cambio=1;
          ++pos.second;
          return glm::vec3(-7.5f,0.0f,0.0f);
        }
    }
  if(modeloAux[3][0] <= -4.0)
    {
      if(pos.second - 1 < M and pos.second-1 >= 0  and
         escenario[pos.first][pos.second-1]->mAllowable)
        {
          cambio=1;
          --pos.second;
          return glm::vec3(7.5f,0.0f,0.0f);
        }
    }
  if(modeloAux[3][2] <= -3.3)
    {
      if(pos.first-1 < N and pos.first-1 >=0 and
         escenario[pos.first-1][pos.second]->mAllowable)
        {
          cambio=1;
          --pos.first;
          return glm::vec3(0.0f,0.0f,7.5f);
        }
    }
  if(modeloAux[3][2] >= 4.5)
    {
      if(pos.first+1 < M and pos.first+1 >=0 and
         escenario[pos.first+1][pos.second]->mAllowable)
        {
          cambio=1;
          ++pos.first;
          return glm::vec3(0.0f,0.0f,-7.5f);
        }
    }
  return glm::vec3(0.0f);

  // float limits[] = {4.0 , -4.0 , -3.3 , 4.5};
  // pair< int, int > direction = { {1,0} , {-1,0} , {0,1} , {0,-1} };
  // pair< int, int > rec = { {3,0} , {3,0} , {3,2} , {3,2} };
  // float movings = 7.8f;
  // glm::vec3 answers { glm::vec3(-movings,0.0f, 0.0f),glm::vec3(movings, 0.0f , 0.0f) ,
  //     glm::vec3(0.0f,0.0f,movings) , glm::vec3(0.0f, 0.0f , -movings)      };
  // for(int i = 0 ; i < 4; ++i)
  //   {
  //     if(limits[i] > 0 )
  //       {
  //         if(modeloAux[rec[i].first][rec[i].second] >= limits[i])
  //           {
  //             if(validate(escenario, {pos.first + direction[i].first ,
  //                     pos.second + direction[i].second  }, N, M ))
  //               {
  //                 pos.first += direction[i].first;
  //                 pos.second+= direction[i].second;
  //                 return answers[i];
  //               }
  //           }
  //       }
  //     else
  //       {
  //         if(modeloAux[rec[i].first][rec[i].second] <= limits[i])
  //           {
  //             if(validate(escenario, {pos.first + direction[i].first ,
  //                     pos.second + direction[i].second  }, N, M ))
  //               {
  //                 pos.first += direction[i].first;
  //                 pos.second+= direction[i].second;
  //                 return answers[i];
  //               }
  //           }
  //       }
  //   }
  // return glm::vec3(0.0f);
}


bool validateCollision(float xBullet , float zBullet, float xEnemy , float zEnemy , float sizeRadius)
{
  if(xEnemy - sizeRadius <= xBullet and xEnemy + sizeRadius >= xBullet
     and  zEnemy - sizeRadius <= zBullet  and  zEnemy + sizeRadius >= zBullet)
    return 1;
  return 0;

}
