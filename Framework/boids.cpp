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
#include "Framework/myArt.hpp"
#include "Framework/myPhisics.hpp"

using namespace std;
typedef vector < Solid< Shape<GLfloat *> >  * >  bandada;
#define MAXDIST 5.0f
#define MAXRADIUS 10.0f
#define MAXANGLE 1.5f

#define LIMITS 4.0f


bool isInRange(bandada & boids , int i , int j )
{
  glm::vec3 myPos = boids[i]->getPos();
  glm::vec3 uPos = boids[j]->getPos();
  glm::vec3 myVel = boids[i]->getPos();
  glm::vec3 uVel = boids[j]->getPos();
  float dist = glm::length(myPos - uPos);
  float angle = glm::acos( glm::dot(myVel,uVel) / (glm::length(myVel) * glm::length(uVel)) );
  if( dist < MAXRADIUS  and angle < MAXANGLE)
    return true;
  return false;
}


glm::vec3 cohesion( bandada & boids , int myIndex)
{
  glm::vec3 myPosition = boids[myIndex]->getPos() , massCentre = glm::vec3(0.0f);
  for(int i = 0 ;i < boids.size() ; ++i)
    if(i != myIndex and isInRange(boids,myIndex,i))
      {
        massCentre += boids[i]->getPos();
      }
  return (massCentre - myPosition);
}


glm::vec3 separation( bandada & boids, int myIndex)
{
  glm::vec3 myPosition = boids[myIndex]->getPos(), diff = glm::vec3(0.0f);

  for(int i = 0 ;i < boids.size() ; ++i)
    {
      if(i != myIndex and isInRange(boids,myIndex,i))
        {
          float dist = glm::length( boids[i]->getPos() - myPosition );
          // cout << dist << "\n";
          if(dist < MAXDIST)
            diff += myPosition - boids[i]->getPos();
        }
    }
  // cout << "Diferencia : "<<glm::to_string(diff) << "\n";
  return diff;
}



glm::vec3 alignment(bandada & boids , int myIndex)
{
  glm::vec3 velAvg = glm::vec3(0.0f) , myVel = boids[myIndex]->vel;
  for(int i = 0 ;i < boids.size() ; ++i)
    {
      if(i != myIndex and isInRange(boids,myIndex,i))
        {
          velAvg += boids[i]->vel ;
        }
    }
  return velAvg;
  // return // (myVel - velAvg/boids.size() )
  //   ;
}



glm::vec3 limitVelocity(glm::vec3 vel)
{
  float vlim = 0.03f, myv =glm::length(vel);
  // cout << myv << "\n";
  if(myv > vlim)
    {
      vel = (vel/myv)*vlim;
    }
  return vel;
}


glm::vec3 collision(bandada & boids , int myIndex)
{
  glm::vec3 myPos = boids[myIndex]->getPos();

  glm::vec3 limiteZ = glm::vec3(0.0f,0.0f,LIMITS);
  glm::vec3 limiteX = glm::vec3(LIMITS,0.0f,0.0f);

  glm::vec3 acum = glm::vec3(0.0f);

  if( limiteZ.z-myPos.z  < 1.0f or  limiteX.x - myPos.x < 1.0f)
    {

      if(limiteX.x - myPos.x < 1.0f)
        {
          cout  << "aca estoy bld \n";
          acum += myPos - limiteX ;

        }
      if(limiteZ.z-myPos.z  < 1.0f)
        acum += myPos - limiteZ ;
      return acum;
    }


  // if(myPos.x > LIMITS or myPos.x < -LIMITS or
  //    myPos.y > LIMITS or myPos.y < -LIMITS or
  //    myPos.z > LIMITS or myPos.z < -LIMITS
  //    )
  //   {

  //     // return boids[myIndex]->vel * -10000;
  //     // return glm::vec3(100000000000.0f,0.0f,0.0f);
  //   }
  return glm::vec3(0.0f);
}

