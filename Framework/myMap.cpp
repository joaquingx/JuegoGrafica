#include <iostream>
#include <utility>
#include <vector>
#define n 5
using namespace std;

typedef pair<int,int> pii;

class Nodo
{
public:
    vector<pii> mEnemies;
    bool mAllowable;
    int mVisited;
    Nodo(bool allowable, int numEnemies, int visited = 0)
    {
        mAllowable = allowable;
        for(int i = 0; i < numEnemies; i++)
        {
            mEnemies.push_back(make_pair(2,3));
        }
        mVisited = visited;
    }
};

class Map{
public:
    Nodo* dungeon[n][n];
    bool* place;
    pii wall[4];
    pii nonWall[4];
    long long int steps;
    Map(long long int pasos)
    {
        wall[0] = make_pair(1,0); wall[1] = make_pair(0,1); wall[2] =  make_pair(-1,0); wall[3] = make_pair(0,-1);
        nonWall[0] = make_pair(0,-1); nonWall[1] =  make_pair(-1,0); nonWall[2] = make_pair(0,1); nonWall[3] = make_pair(1,0);
        steps = pasos;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                dungeon[i][j] = new Nodo(0,1);
            }
        }
    }
    inline bool validPlace(pii& ant)
    {
        return (ant.first < n and ant.second < n) && (ant.first > -1 && ant.second > -1);
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
            for(int j = 0; j < n; j++)
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
        int i = 1;
        pii ant = make_pair(n/2,n/2), previous_ant;
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
        cout<<"Acabo"<<endl;
        fix();
    }
    void printMap()
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout<<dungeon[i][j]->mAllowable;
            }
            cout<<endl;
        }
    }

};

