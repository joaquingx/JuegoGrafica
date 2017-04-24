#include <string>
#include <GL/glew.h>
// Include GLFW
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace std;
using namespace glm;

#ifndef MYCONFIGURATION_HPP
#define MYCONFIGURATION_HPP

int init(std::string name,int width, int heigth, GLFWwindow *& window,GLuint& VertexArrayID);
void activateAttribs(int n);
void deactivateAttribs(int n);
void getAHandle(GLuint idShader,string name);
#endif
