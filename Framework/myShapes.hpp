#ifndef MYSHAPES_HPP
#define MYSHAPES_HPP

class Shape{
public:
  int mySize;
  GLfloat * myShape;
  GLuint vertexBuffer;
  Shape();
  ~Shape();
  void bindShape();
  void bindBuffer(int layout);
};

class Triangle: public Shape{
public:
  Triangle();
  void createShape();
};

class Cube: public Shape{
public:
  Cube();
  void createShape();
};

class CubeColor: public Shape{
  public:
  CubeColor(int who);
  void createShape(int who);
};

#endif
