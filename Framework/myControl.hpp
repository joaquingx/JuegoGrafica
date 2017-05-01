#ifndef MYCONTROL_HPP
#define MYCONTROL_HPP

void computeMatrices();
void moveShape();
glm::mat4 getViewMatrix();
glm::mat4 getProjectionMatrix();
glm::vec3 getTranslateMatrix();
glm::mat4 getRotationMatrix();
bool validatePosition(glm::mat4 Modelo, float maxX , float minX , float maxZ, float minZ);
#endif
