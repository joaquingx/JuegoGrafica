#ifndef MYART_HPP
#define MYART_HPP
#include <vector>

template<class T>
class Art{
public:
  int mySize;
  GLuint vertexBuffer;
  T myArt;
  Art();
  ~Art();
  void bindArt();
  void bindArt(int algo);
  void bindBuffer(int layout,int theSize , bool toDraw, int nTriangles);
};


template<class T>
class Shape: public Art<T>{
public:
  Shape(int mySize, T myShape);
  Shape();
  ~Shape();
};

template<class T>
class Texture: public Art<T>{
public:
  GLuint myIDTexture;
  Texture(char * path, int mySize, T myTexture);
  Texture();
  ~Texture();
  void bindTexture(int TextureID, int identifier,int layout, int theSize);
};

template<class T , class T2>
class Model{
public:
  Shape<T>  * myVertices, * myNormal;
  Texture<T2>  * myUvs;
  bool myModel;
  Model(char * path,char * pathTexture);
  ~Model();
  void bindModel(int identifier, int TextureID, int layoutVertice,int layoutTexture, int layoutNormal);
};

template<class T>
class Color: public Art<T>{
public:
  Color();
  ~Color();
};

#endif
