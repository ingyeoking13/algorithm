/*
   maximum flow , BFS Approach (SPFA) 
   https://www.acmicpc.net/problem/6086
*/

#include <iostream>
#define VERTEX (int)1e3

using namespace std;
struct Queue
{
  int queue[MAXSIZE];
  int h, t;
  Queue()
  {
    h=t=0;
  }
  void push(int id)
  {
    queue[t++] = id;
  }
  int front()
  {
    return queue[h];
  }
  void pop () { h++;}
  bool empty() { return h==t; }
};

struct MaximumFlow
{
  bool v[VERTEX];
  int e[VERTEX][VERTEX];
  int pred[VERTEX];
  int n, m;
  Queue q;

  Bipartie()
  {
    for (int i=0; i<VERTEX; i++)
    {
      for (int j=0; j<VERTEX; j++)
      {
        e[i][j] = 0;
      }
      pred[i] = -1;
    }
  }

  int maximum_matching( int st )
  {
    int ans =0;
    while(true)
    {
      for (int i=0;i<n; i++)
      {
        v[i] = false;
        pred[i] = -1;
      }

      q.push(st);
      v[st]=true;
      while(!q.empty())
      {
        int now = q.front();
        q.pop();

        for (int i=0; i<52; i++)
        {
          if (capa[now][i] > 0)
          {
            if ( v[i] ) continue;
            v[i] =true;
            pred[i] =now;
            q.push(i);
          }
        }
      }

      int now = 25;
      if (pred[now] )...


    }
  }
};

Bipartie bipartie;

int main()
{

  int n, m;
  cin >> n >> m;
  bipartie.n = n;
  bipartie.m = m;
  for (int i=0; i<n; i++)
  {
    int t;
    cin >> t;
    while(t--)
    {
      int u;
      cin >> u;
      bipartie.e[i][u-1] = true;
    }
  }
  cout << bipartie.maximum_matching() << "\n";
}
