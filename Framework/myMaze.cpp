#ifndef MYMAZE_HPP
#define MYMAZE_HPP
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef vector<char> vch;


//No es la solucion correcta.

/*void WallAdder(int n, int m, int k, vector<vch>& Maze)
{
    int i = 0, j = 0, minj = 0, mini = 0, cont = 0;
    int nm = n*m;
    while(cont < nm)
    {
        for(j = minj; j < m; j++)
        {
            if(Maze[i][j] == '.' and k > 0)
            {
                Maze[i][j] = 'X';
                k--;
                if(k == 0)
                {
                    return;
                }
            }
            cont++;

        }
        j--;
        mini++;
        for(i = mini; i < n; i++)
        {
            if(Maze[i][j] == '.' and k > 0)
            {
                Maze[i][j] = 'X';
                k--;
                if(k == 0)
                {
                    return;
                }
            }
            cont++;
        }
        i--;
        m--;
        for(j = m-1; j >= minj; j--)
        {
            if(Maze[i][j] == '.' and k > 0)
            {
                Maze[i][j] = 'X';
                k--;
                if(k == 0)
                {
                    return;
                }
            }
            cont++;
        }
        j++;
        n--;
        for(i = n -1; i >= mini; i--)
        {
            if(Maze[i][j] == '.' and k > 0)
            {
                Maze[i][j] = 'X';
                k--;
                if(k == 0)
                {
                    return;
                }
            }
            cont++;
        }
        i++;
        minj++;
    }
    return;
}*/



class GNodo
{
public:
    char character;
  int m_i,m_j;
    vector<GNodo*> adja;
    vector<GNodo*> Children;
    GNodo* Father;
    bool leaf;
    bool visited;
  GNodo(char character)
    {
        this->character = character;
        leaf = false;
        visited = false;
    }
};

class Grafo
{
public:
    vector<vector<GNodo*> > GNodos;
    vector<GNodo*> STree;
    GNodo* Dummy;
    Grafo(/*vector<vector<GNodo*> >& GNodos*/)
    {
      //this->GNodos = GNodos;
        this->Dummy = new GNodo('#');
    }
  void DoItAll(vector<vector<bool> >& map, int k){
    int ix = 0, jx = 0;
    bool flag = false;
    vector<vch> real_map;
    vector<GNodo*> line;
    vector<vector<GNodo*> > Maze;
    vch test;
    
    for(int i = 0; i < map.size(); i++)
    {
      test.clear();
      for(int j = 0; j < map[i].size(); j++)
      {
	if(map[i][j] == true) test.push_back('.');
	else test.push_back('#');
      }
      real_map.push_back(test);
    }
    
    for(int i = 0; i < real_map.size(); i++)
    {
        line.clear();
        for(int j = 0; j < real_map[i].size(); j++)
        {
            if(real_map[i][j] == '.' and flag == false)
            {
                ix = i;
                jx = j;
                flag = true;
            }
            line.push_back(new GNodo(real_map[i][j]));
	    line.back()->m_i = i;
	    line.back()->m_j = j;
        }
        Maze.push_back(line);
    }
    
    //Grafo Graph(Maze);
    this->GNodos = Maze;
    Join();
    DFS(Maze[ix][jx]);

    while(k > 0)
    {
        WallAdder(k);
    }
  }
    GNodo* Search(int i, int j)
    {
        if(i >= 0 and j >= 0 and i < GNodos.size() and j < GNodos[i].size())
        {
            return GNodos[i][j];
        }
        return Dummy;
    }
    void Join()
    {
        for(int i = 0; i < GNodos.size(); i++)
        {
            for(int j = 0; j < GNodos[i].size(); j++)
            {
                GNodos[i][j]->adja.push_back(Search(i-1, j));
                GNodos[i][j]->adja.push_back(Search(i+1, j));
                GNodos[i][j]->adja.push_back(Search(i, j-1));
                GNodos[i][j]->adja.push_back(Search(i, j+1));
            }
        }
    }
    void DFS(GNodo* Start)
    {
        vector<GNodo*> Stack;
        Stack.push_back(Start);
        while(Stack.size() > 0)
        {
            Start = Stack.back();
            Stack.pop_back();

            if(Start->visited == false and Start->character != '#')
            {
                for(int i = 0; i < Start->adja.size(); i++)
                {
                    Start->visited = true;
                    Stack.push_back(Start->adja[i]);
                    Start->adja[i]->Father = Start;
                    if(Start->adja[i]->character != '#' and Start->adja[i]->visited != true)
                    {
                        Start->Children.push_back(Start->adja[i]);
                    }
                }
                /*if(Start->m_i != 0 and Start->m_j != 0)*/ STree.push_back(Start);
            }
        }
    }
    bool Check(vector<GNodo*> GNodes)
    {
        for(int i = 0; i < GNodes.size(); i++)
        {
            if(GNodes[i]->character == '.')
            {
                return false;
            }
        }
        return true;
    }
    void WallAdder(int& k)
    {
        for(int i = STree.size()-1; i >= 0; i--)
        {
            if(STree[i]->character != '#' and STree[i]->character != 'X')
            {
	      if(Check(STree[i]->Children) == true) //Sapbe
                {
                    k--;
                    STree[i]->character = '#';
                    if(k == 0)
                    {
                        return;
                    }
                }
            }
        }
        return;
    }
  void addWalls(int& k){
    while(k>0){
      WallAdder(k);
    }
  }
    void Print()
    {
        for(int i = 0; i < GNodos.size(); i++)
        {
            for(int j = 0; j < GNodos[i].size(); j++)
            {
                cout<<GNodos[i][j]->character;
            }
            cout<<endl;
        }
        return;
    }

  vector<vector<bool> > endItAll(){
    vector<bool> line;
    vector<vector<bool> > real_map;
    for(int i = 0; i < GNodos.size(); i++)
        {
	  line.clear();
            for(int j = 0; j < GNodos[i].size(); j++)
            {
	      if(GNodos[i][j]->character == '.') line.push_back(true);
	      else line.push_back(false);
            }
            real_map.push_back(line);
        }
    return real_map;
  }
};





/*int main()
{
    ios_base::sync_with_stdio(false);
    int n, m, k, ix = 0, jx = 0;
    bool flag = false;
    char x;
    vector<GNodo*> line;
    vector<vector<GNodo*> > Maze;
    cin>>n;
    cin>>m;
    cin>>k;
    for(int i = 0; i < n; i++)
    {
        line.clear();
        for(int j = 0; j < m; j++)
        {
            cin>>x;
            if(x == '.' and flag == false)
            {
                ix = i;
                jx = j;
                flag = true;
            }
            line.push_back(new GNodo(x));
        }
        Maze.push_back(line);
    }
    Grafo Graph(Maze);
    Graph.Join();
    Graph.DFS(Maze[ix][jx]);
    while(k > 0)
    {
        Graph.WallAdder(k);
    }

    Graph.Print();
    return 0;
}*/


#endif
