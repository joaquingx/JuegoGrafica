#ifndef MYMAP_HPP
#define MYMAP_HPP
#include <iostream>
#include <utility>
#include <vector>
#include <time.h>
#include <unistd.h>
#include "myMaze.cpp"

using namespace std;

typedef pair<int,int> pii;


class Nodo
{
public:
  int idx;
  vector<pii> mEnemies,mWalls;
  bool mAllowable;
  int mVisited;
  Nodo(bool allowable, int numEnemies ,  int numWalls, int idx = -1, int visited = 0)
  {
    this->idx = idx;
    mAllowable = allowable;
    for(int i = 0; i < numEnemies; i++)
      {
        int randX = (rand() % 7) - 3;
        int randZ = (rand() % 7) - 3;
        mEnemies.push_back(make_pair(randX,randZ));
      }
    for(int i = 0; i < numWalls; i++)
      {
        int randX = (rand() % 7) - 3;
        int randZ = (rand() % 7) - 3;
        mWalls.push_back(make_pair(randX,randZ));
      }
    mVisited = visited;
  }
};

class Map{
public:
  //Nodo* dungeon[n][n];
  vector<vector<Nodo*> > dungeon;
  bool* place;
  pii wall[4];
  pii nonWall[4];
  long long int steps;
  int m_free_spaces, n, m;
  Map(long long int pasos, int free_spaces, int x, int y)
  {
    vector<Nodo*> line;
    n = x;
    m = y;
    m_free_spaces = free_spaces;
    // generateMap();
    srand(time(NULL));
    wall[0] = make_pair(1,0); wall[1] = make_pair(0,1); wall[2] =  make_pair(-1,0); wall[3] = make_pair(0,-1);
    nonWall[0] = make_pair(0,-1); nonWall[1] =  make_pair(-1,0); nonWall[2] = make_pair(0,1); nonWall[3] = make_pair(1,0);
    steps = pasos;

    for(int i = 0; i < n; i++){
      line.clear();
      for(int j = 0; j < m; j++){
	line.push_back(NULL);
      }
      dungeon.push_back(line);
    }
    //cout<<dungeon.size()<<" "<<dungeon[0].size()<<endl;
    // int randX =  0;
    // int randY =  0;
    // cout << randX << " " << randY << "\n";
    for(int i = 0; i < n; i++)
      {
        for(int j = 0; j < m; j++)
          {
            int cEnemies = (rand() % 3) + 1;
            int cWalls = (rand() % 3) + 1;
            // if( i == randX and j == randY)
            //   {
            //     int wIdx = rand() % (cEnemies + 1);
            //     dungeon[i][j] = new Nodo(0,cEnemies,1);
            //   }
            // else if( i == randX2 and j == randY2)
            //   {
            //     int wIdx = rand() % (cEnemies + 1);
            //     dungeon[i][j] = new Nodo(0,cEnemies,2);
            //   }
            // else
              dungeon[i][j] = new Nodo(0,cEnemies,cWalls);
          }
      }
  }

  void assignKeys()
  {
    int randX =  rand() % n;
    int randY =  rand() % m;
    int randX2 = rand() % n;
    int randY2 = rand() % m;
    while(!dungeon[randX][randY]->mAllowable)
      {
        randX = rand() % n;
        randY = rand() % m;
      }
    dungeon[randX][randY]->idx = 1;

    while(!dungeon[randX2][randY2]->mAllowable or (randX == randX2 and randY == randY2) )
      {
        randX2 = rand() % n;
        randY2 = rand() % m;
      }
    dungeon[randX2][randY2]->idx = 2;
    cout << "La llave esta : " << randX << " "  << randY  << "\n";
    cout << "El Cuarto blanco esta  : " << randX2 << " "  << randY2  << "\n";

  }

  inline bool validPlace(pii& ant)
  {
    return (ant.first < n and ant.second < m) && (ant.first > -1 && ant.second > -1);
  }

  pii DFS(pii start, int num)
  {
    vector<pii> next;
    next.push_back(start);
    while(!next.empty())
      {
        start = next.back();
        dungeon[start.first][start.second]->mVisited = num;
        next.pop_back();
        start.first++;
        if(validPlace(start) and dungeon[start.first][start.second]->mAllowable and dungeon[start.first][start.second]->mVisited == 0) next.push_back(start);
        start.first-=2;
        if(validPlace(start) and dungeon[start.first][start.second]->mAllowable and dungeon[start.first][start.second]->mVisited == 0) next.push_back(start);
        start.first++; start.second--;
        if(validPlace(start) and dungeon[start.first][start.second]->mAllowable and dungeon[start.first][start.second]->mVisited == 0) next.push_back(start);
        start.second+=2;
        if(validPlace(start) and dungeon[start.first][start.second]->mAllowable and dungeon[start.first][start.second]->mVisited == 0) next.push_back(start);
        start.second--;
      }
    return start;
  }
  void joinTwo(pii start, pii finish)
  {

    while(start != finish)
      {
        if(start.first < finish.first) start.first++;
        dungeon[start.first][start.second]->mAllowable = 1;
        if(start.second < finish.second) start.second++;
        dungeon[start.first][start.second]->mAllowable = 1;
        if(start.first > finish.first) start.first--;
        dungeon[start.first][start.second]->mAllowable = 1;
        if(start.second > finish.second) start.second--;
        dungeon[start.first][start.second]->mAllowable = 1;
      }
    return;

  }
  void fix()
  {
    int num = 1;
    vector<pii> endings;
    for(int i = 0; i < n; i++)
      {
        for(int j = 0; j < m; j++)
          {
            if(dungeon[i][j]->mAllowable and dungeon[i][j]->mVisited == 0)
              {
                endings.push_back(DFS(make_pair(i,j), num));
                num++;
              }
          }
      }
    cout<<"acabo2"<<endl;
    for(int i = 1; i < endings.size(); i++)
      {
        joinTwo(endings[i-1],endings[i]);
      }
    return;
  }
  void generateMap()
  {
    int i = 1, free_spaces = 0;
    pii ant = make_pair(n/2,m/2), previous_ant;
    for(;steps > 0; steps--)
      {
        place = &(dungeon[ant.first][ant.second]->mAllowable);
        previous_ant = ant;
        //i = 1;
        if(*place == 0)
          {
            ant.first += wall[i].first; ant.second += wall[i].second;
            while(!validPlace(ant))
              {
                ant = previous_ant;
                ant.first += wall[i].first; ant.second += wall[i].second;
                i = (i + 1) % 4;
              }
            *place = 1;
          }
        else
          {
            ant.first += nonWall[i].first; ant.second += nonWall[i].second;
            while(!validPlace(ant))
              {
                ant = previous_ant;
                ant.first += nonWall[i].first; ant.second += nonWall[i].second;
                i = (i + 1) % 4 ;
              }
            *place = 0;
          }
      }
    dungeon[0][0]->mAllowable = 1;
    // cout<<"Acabo"<<endl;
    fix();

    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
	if(dungeon[i][j]->mAllowable) free_spaces++;
      }
    }

    cout<<"espacios libres: "<<free_spaces<<endl;
    cout<<"espacios todo: "<<m_free_spaces<<endl;
    
    vector<vector<bool> > new_map;
    if(free_spaces > m_free_spaces){
      cout<<"more free spaces"<<endl;
      new_map = convert();
      Grafo Graph;
      free_spaces -= m_free_spaces;
      cout<<"resta: "<<free_spaces<<endl;
      printMap();

      cout<<endl;
      for(int i = 0; i < n; i++){
	for(int j = 0; j < m; j++){
	  cout<<new_map[i][j];
	}
	cout<<endl;
      }
      
      Graph.DoItAll(new_map,free_spaces);
      cout<<"s"<<endl;
      new_map.clear();
      new_map = Graph.endItAll();
      for(int i = 0; i < n; i++){
	for(int j = 0; j < m; j++){
	  dungeon[i][j]->mAllowable = new_map[i][j];
	}
      }
    }
    
    else if(free_spaces < m_free_spaces){
      cout<<"entro!"<<endl;
      for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++)
	  if(!dungeon[i][j]->mAllowable){
	    dungeon[i][j]->mAllowable = 1;
	    free_spaces++;
	    if(free_spaces == m_free_spaces) return;
	  }
    }
  }
  void printMap()
  {
    for(int i = 0; i < n; i++)
      {
        for(int j = 0; j < m; j++)
          {
            cout<<dungeon[i][j]->mAllowable;
          }
        cout<<endl;
      }
  }

  vector<vector<bool> > convert(){
    vector<bool> line;
    vector<vector<bool> > real_map;
    for(int i = 0; i < n; i++){
      line.clear();
      for(int j = 0; j < m; j++){
	line.push_back(dungeon[i][j]->mAllowable);
      }
      real_map.push_back(line);
    }
    return real_map;
  }

};


#endif
