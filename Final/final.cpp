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
// #include "Framework/myShapes.hpp"
#include "Framework/myControl.hpp"
#include "Framework/myObjectLoader.hpp"
#include "Framework/myTexture.hpp"
#include "Resources/verticesArt.cpp"
#include "Framework/myArt.hpp"
#include "Framework/myPhisics.cpp"
#include "Framework/myMap.cpp"

const int TAMCUBE = 432;
GLFWwindow * window;
GLuint VertexArrayID;


// class cuarto

void regenerateMap( list < Solid< Shape<GLfloat *> >  * > & solidWalls , Map  * mapa,   pair<int,int> & pos)
{
  solidWalls.clear();
  for(int i = 0 ; i < mapa->dungeon[pos.first][pos.second]->mWalls.size() ; ++i)
    {
      float myX = float(mapa->dungeon[pos.first][pos.second]->mWalls[i].first);
      float myZ = float(mapa->dungeon[pos.first][pos.second]->mWalls[i].second);
      solidWalls.push_back( new Solid< Shape<GLfloat *> >(new Shape<GLfloat * >(TAMCUBE,verticesCube),glm::scale(glm::mat4(1.0f),vec3(0.6f))
                                                          ,glm::mat4(1.0f),glm::translate(glm::mat4(1.0f),glm::vec3(myX,2.0f,myZ)), 10.0f));
    }
}

void regenerateEnemies(list< Solid < Shape < GLfloat * > > * > & solidEnemy, Map * mapa, pair<int,int> & pos)
{
  for(int i = 0 ; i < mapa->dungeon[pos.first][pos.second]->mEnemies.size() ; ++i)
    {
      float myX = float(mapa->dungeon[pos.first][pos.second]->mEnemies[i].first);
      float myZ = float(mapa->dungeon[pos.first][pos.second]->mEnemies[i].second);
      // cout << myX << " " << myZ;
      solidEnemy.push_back(  new Solid< Shape<GLfloat *> >(new Shape<GLfloat * >(TAMCUBE,verticesCube),glm::scale(glm::mat4(1.0f),vec3(0.3f))
                                                           ,glm::mat4(1.0f),glm::translate(glm::mat4(1.0f),glm::vec3(myX,2.0f,myZ)), 10.0f));
    }
}

void regenerateMiniMap(int N, int M , vector< vector < Solid< Shape<GLfloat *>  > *  > >  & solidMapping, Map * mapa)
{
  glm::vec3 xMov,zMov;
  xMov = glm::vec3(1.0f,0.0f,0.0f);
  zMov = glm::vec3(0.0f,0.0f,1.0f);
  solidMapping.resize(N);
  glm::mat4 firstTraslationMatrix = glm::mat4(1.0f);
  for(int i = 0 ; i < N ; ++i)
    {
      solidMapping[i].resize(M);
      for(int j = 0 ; j < M ; ++j)
        {
          solidMapping[i][j] = new Solid< Shape <GLfloat * > > (new Shape<GLfloat * >(TAMCUBE,verticesCube),glm::scale(glm::mat4(1.0f),vec3(0.5f,0.2f,0.5f))
                                                                ,glm::mat4(1.0f),firstTraslationMatrix, 10.0f);
          firstTraslationMatrix = glm::translate( firstTraslationMatrix , xMov);
        }
      firstTraslationMatrix = glm::translate( firstTraslationMatrix , -xMov * N);
      firstTraslationMatrix = glm::translate( firstTraslationMatrix , zMov );
    }
}

void reRandom(int & N , int & M  , int & free_spaces)
{
  N = rand() % 4 + 2;
  M = rand() % 4 + 2;
  free_spaces = rand() % (N*M);
  // N = 2;
  // M = 2;
  // free_spaces = 3;
}

int main( void )
{
  int N, M, free_spaces;
  //Aux Varibales;
  // cin>>N>>M>>free_spaces;
  srand(time(NULL));
  reRandom(N,M,  free_spaces);
  int cnt = 0 ;
  Map * mapa;
  mapa = new Map(rand() % 50000, free_spaces, N, M);
  mapa->generateMap();
  mapa->assignKeys();
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
  strcpy(resObj,"../Resources/hormiga.obj");// ya se que es inseguro :'(
  strcpy(resTexture,"../Resources/hormiga.dds");// ya se que es inseguro :'(
  //strcpy(resTexturaRoca,"../Resources/textureroca.DDS");// ya se que es inseguro :'(
  // strcpy(resTexturaRoca,"../Resources/uvtemplate.DDS");// ya se que es inseguro :'(
  // GLuint TextureRocaID  = glGetUniformLocation(programID, "myTextureSampler");
  // Solid<GLfloat * > ;
  // Solids Shapes.

  // Solid< Shape<GLfloat *> >  solidPlane(new Shape<GLfloat * >(TAMCUBE,verticesCube),glm::mat4(1.0f),10.0f);
  Solid< Shape<GLfloat *> >  solidPlane(new Shape<GLfloat * >(TAMCUBE,verticesCube),glm::scale(glm::mat4(1.0f),vec3(4.5f,1.0f,4.5f))
                                        ,glm::mat4(1.0f),glm::mat4(1.0f), 10.0f);

  glm::mat4 moverModelo = glm::translate(glm::mat4(1.0f), glm::vec3(-7.5f,1.0f,-7.5f) );
  vector< vector < Solid< Shape<GLfloat *>  >  *  > > solidMapping;


  list < Solid< Shape<GLfloat *> >  * > solidEnemy;

  list < Solid< Shape<GLfloat *> >  * > solidWalls;


  list < Bullet< Shape<GLfloat *> > *  >  solidBullets;
  pair<int,int> pos = {0,0};
  pair<int, int> actdir= {0,1};
  int newState=GLFW_RELEASE,oldState=GLFW_RELEASE;


  mapa->printMap();
  Solid< Model< vector< glm::vec3 > , vector< glm::vec2 > > > solidSuzane( new Model< vector< glm::vec3 >, vector< glm::vec2 > >(resObj,resTexture) ,
                                                                           glm::scale(glm::mat4(1.0f),vec3(0.4f)),glm::mat4(1.0f),glm::translate(glm::mat4(1.0f),glm::vec3(1.0f,2.0f,1.0f)) , 5.0f);

  Solid< Shape<GLfloat *> >   * solidKey = 0;
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

  float speed = 0.01f;
  bool flag = 0, tengoLaLlave = 0;


  solidBullets.clear();

  regenerateEnemies(solidEnemy,mapa,pos);
  regenerateMap(solidWalls,mapa,pos);
  regenerateMiniMap(N,M,solidMapping, mapa);

  // vecotr esolidWin
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


    if(mapa->dungeon[pos.first][pos.second]->idx ==  2)
      {
        if(tengoLaLlave)
          {
            reRandom(N,M,free_spaces);
            mapa = new Map(rand() % 50000, free_spaces, N, M);
            mapa->generateMap();
            mapa->assignKeys();
            pos = {0,0};
            regenerateMap(solidWalls,mapa,pos);
            regenerateMiniMap(N,M,solidMapping, mapa);
            regenerateEnemies(solidEnemy,mapa,pos);
            sleep(2.0);
            tengoLaLlave = 0;
            cout << "Ganaste brou\n";
            // return 0;
          }
        glUniform1f(forbidden,2);
      }

    if(mapa->dungeon[pos.first][pos.second]->idx == 1 and !tengoLaLlave)
      {
        solidKey = new Solid< Shape<GLfloat *>  >(new Shape<GLfloat * >(TAMCUBE,verticesCube),glm::scale(glm::mat4(1.0f),vec3(0.4f)),glm::translate(glm::mat4(1.0f),glm::vec3(0.0f,2.0f,0.0f))
                                                  ,glm::mat4(1.0f), 10.0f);
        // cout << "entre papirrin\n";
        // glUniform1f(forbidden,2);
      }
    else
      {
        solidKey = 0;
        // glUniform1f(forbidden,1);
      }
    MVP = Projection * View * solidPlane.modelMatrix;
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    solidPlane.solidArt->bindBuffer(0,3,1,36);

    // MVP = Projection * View * solidEnemy.modelMatrix
    // glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    // solidEnemy.solidArt->bindBuffer(0,3,1,36);

    moveShape();
    glm::mat4 modeloAux = glm::translate(solidSuzane.traslationMatrix , getTranslateMatrix());

    bool collisionWithWall = 0;
    // Collision with walls
    for(auto it = solidWalls.begin() ; it != solidWalls.end() ; ++it)
      {
        // Collision with monkey
        float xWall = (*it)->modelMatrix[3][0], zWall = (*it)->modelMatrix[3][2];
        if( validateCollision(modeloAux[3][0],modeloAux[3][2], xWall , zWall,  0.88))
          {
            collisionWithWall=1;
          }
      }
    bool validPosition = validatePosition(modeloAux,4.0,-4.0,4.5,-3.3);
    if(validPosition and !collisionWithWall) // falta valida posiciones
      solidSuzane.setTraslationMatrix(modeloAux);
    else // o es un limite o  me voy a otro escenario
      {
        bool regenerar;
        solidSuzane.setTraslationMatrix(glm::translate(solidSuzane.traslationMatrix,
                                                       changeScenario(modeloAux,pos,mapa->dungeon, N ,M,regenerar)));
        // cout << mapa->dungeon[pos.first][pos.second]->mEnemies.size() << "..gtam\n";
        if(regenerar)
          {
            solidEnemy.clear();
            solidWalls.clear();
            for(int i = 0 ; i < mapa->dungeon[pos.first][pos.second]->mEnemies.size() ; ++i)
              {
                float myX = float(mapa->dungeon[pos.first][pos.second]->mEnemies[i].first);
                float myZ = float(mapa->dungeon[pos.first][pos.second]->mEnemies[i].second);
                // cout << myX << " " << myZ;
                solidEnemy.push_back(  new Solid< Shape<GLfloat *> >(new Shape<GLfloat * >(TAMCUBE,verticesCube),glm::scale(glm::mat4(1.0f),vec3(0.3f))
                                                                     ,glm::mat4(1.0f),glm::translate(glm::mat4(1.0f),glm::vec3(myX,2.0f,myZ)), 10.0f));
              }
            for(int i = 0 ; i < mapa->dungeon[pos.first][pos.second]->mWalls.size() ; ++i)
              {
                float myX = float(mapa->dungeon[pos.first][pos.second]->mWalls[i].first);
                float myZ = float(mapa->dungeon[pos.first][pos.second]->mWalls[i].second);
                // cout << myX << " " << myZ;
                solidWalls.push_back(  new Solid< Shape<GLfloat *> >(new Shape<GLfloat * >(TAMCUBE,verticesCube),glm::scale(glm::mat4(1.0f),vec3(0.6f))
                                                                     ,glm::mat4(1.0f),glm::translate(glm::mat4(1.0f),glm::vec3(myX,2.0f,myZ)), 10.0f));
              }
          }
      }
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
    if(cnt == 199)
      {
        cout << "Estoy en la posicion " << pos.first << " " << pos.second << "\n";
      }
    newState = glfwGetKey(window, GLFW_KEY_SPACE );

    if(newState == GLFW_PRESS and oldState == GLFW_RELEASE)
      {
        solidBullets.push_back( new Bullet< Shape<GLfloat * > >(new Shape<GLfloat * >(TAMCUBE,verticesCube) , glm::scale(glm::mat4(1.0f),vec3(0.08f))
                                                                ,glm::mat4(1.0f), solidSuzane.traslationMatrix  , 10.0f, actdir ) );
      }
    oldState = newState;
    for(auto it = solidWalls.begin();  it != solidWalls.end() ; ++it)
      {
        MVP = Projection * View * (*it)->modelMatrix;
        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
        (*it)->solidArt->bindBuffer(0,3,1,36);
      }
    //Drawing Bullets
    for(auto it = solidBullets.begin() ; it != solidBullets.end() and (*it) != NULL ; ++it)
      {
        // cout << (*it)->dir.first << " " << (*it)->dir.second << "\n";
        (*it)->setTraslationMatrix( glm::translate( (*it)->traslationMatrix, glm::vec3( (*it)->dir.first * 0.1, 0.0f , (*it)->dir.second * 0.1 ) ) );
        MVP =  Projection * View * (*it)->modelMatrix;
        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
        (*it)->solidArt->bindBuffer(0,3,1,36);
        float xBullet = (*it)->modelMatrix[3][0], zBullet = (*it)->modelMatrix[3][2];
        // Collision with walls
        for(auto itWall = solidWalls.begin() ; itWall != solidWalls.end() ; ++itWall)
          {
            float xWall = (*itWall)->modelMatrix[3][0], zWall = (*itWall)->modelMatrix[3][2];
            if( validateCollision(xBullet, zBullet, xWall , zWall,  0.88))
              {
                if(it == solidBullets.begin())
                  {
                    solidBullets.erase(it);
                    goto trampa;
                  }
                solidBullets.erase(it--);
              }
          }
        for(auto itEnemy = solidEnemy.begin() ; itEnemy != solidEnemy.end() and (*itEnemy) != NULL ; ++itEnemy)
          {
            float xEnemy = (*itEnemy)->modelMatrix[3][0], zEnemy = (*itEnemy)->modelMatrix[3][2];
            if( validateCollision(xBullet , zBullet, xEnemy , zEnemy, 0.5 ) )
              {
                if(solidKey != 0)
                  {
                    flag = 1;
                  }
                if(itEnemy == solidEnemy.begin())
                  {
                    // cout << "soy el primero Enemy\n";
                    solidEnemy.erase(itEnemy++);
                    // itEnemy = solidEnemy.begin();
                  }
                else solidEnemy.erase(itEnemy--);
                if(it == solidBullets.begin())
                  {
                    solidBullets.erase(it);
                    goto trampa;
                  }
                else
                  solidBullets.erase(it--);
              }

          }
      }
  trampa:
    if(flag)
      if(solidKey != 0 )
        {
          // cout << " kha\n";
          MVP = Projection * View * solidKey->modelMatrix;
          glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
          // glUniform1f(forbidden,3);
          solidKey->solidArt->bindBuffer(0,3,1,36);
          float xSuzane = solidSuzane.modelMatrix[3][0], zSuzane = solidSuzane.modelMatrix[3][2];
          float xKey = solidKey->modelMatrix[3][0], zKey = solidKey->modelMatrix[3][2];
          if( validateCollision(xSuzane , zSuzane, xKey , zKey, 1.5 ) )
            {
              // cout << "COlision\n";
              // cout << "Coli"
              solidKey = 0;
              tengoLaLlave = 1;
            }
        }
    glUniform1f(forbidden,0);
    //Drawing Enemies
    for(auto it = solidEnemy.begin() ; it != solidEnemy.end() ; ++it)
      {
        glm::mat4 enemyModel = (*it)->modelMatrix;
        glm::mat4 suzaneModel = solidSuzane.modelMatrix;
        glm::vec3 myEnemy = glm::vec3(enemyModel[3][0], enemyModel[3][1] , enemyModel[3][2]);
        glm::vec3 myMonkey = glm::vec3(suzaneModel[3][0], suzaneModel[3][1], suzaneModel[3][2]);
        glm::vec3 direct = glm::normalize(myMonkey-myEnemy);
        float xSuzane = solidSuzane.modelMatrix[3][0], zSuzane = solidSuzane.modelMatrix[3][2];
        float xEnemy = (*it)->modelMatrix[3][0], zEnemy = (*it)->modelMatrix[3][2];
        // glm::vec3 direct = glm::normalize(myEnemy-myMonkey);
        glm::mat4 nuevo = (*it)->modelMatrix;
        // (*it)->setTraslationMatrix( glm::translate((*it)->traslationMatrix , (direct * speed)) );
        nuevo = glm::translate( nuevo , (direct * 3 *  speed)) ;
        bool collisionExist=0;
        for(auto itWall = solidWalls.begin() ; itWall != solidWalls.end() ; ++itWall)
          {
            float xWall = (*itWall)->modelMatrix[3][0], zWall = (*itWall)->modelMatrix[3][2];
            if(validateCollision(xWall,zWall,nuevo[3][0],nuevo[3][2],0.88))
              {
                collisionExist=1;
              }
          }
        if(!collisionExist)
          (*it)->setTraslationMatrix( glm::translate((*it)->traslationMatrix , (direct * speed)) );
        MVP =  Projection * View * (*it)->modelMatrix;
        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
        (*it)->solidArt->bindBuffer(0,3,1,36);
        if( validateCollision(xSuzane , zSuzane, xEnemy , zEnemy, 0.5 ) )
          {
            cout << "Perdiste brou\n";
            glfwTerminate();
            return 0;
          }
      }

    //Drawing Map
    for(int i = 0 ; i < N ; ++i)
      for(int j = 0 ; j < M ; ++j)
        {
          MVP = Projection * View * moverModelo * solidMapping[i][j]->modelMatrix;
          glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
          glUniform1f(forbidden,4);
          if(i == pos.first and j == pos.second)
            glUniform1f(forbidden,3);
          if(mapa->dungeon[i][j]->mAllowable)
            solidMapping[i][j]->solidArt->bindBuffer(0,3,1,36);
        }

    deactivateAttribs(3);
    cnt = (cnt + 1)%200;
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
