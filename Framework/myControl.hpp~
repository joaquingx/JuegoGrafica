#ifndef MYCONTROL_HPP
#define MYCONTROL_HPP
using namespace glm;
using namespace std;
#include <utility>
#include "myMap.cpp"
void computeMatrices();
void moveShape();
glm::mat4 getViewMatrix();
glm::mat4 getProjectionMatrix();
glm::vec3 getTranslateMatrix();
glm::mat4 getRotationMatrix();
bool validatePosition(glm::mat4 Modelo, float maxX , float minX , float maxZ, float minZ);
glm::vec3 changeScenario( glm::mat4 modeloAux , pair < int , int >  & pos, Nodo * escenario[3][3] , int N , int M, bool & cambio);
pair<int,int> getDirection();
bool validateCollision(float xBullet , float zBullet, float xEnemy , float zEnemy , float sizeRadius);
#endif
