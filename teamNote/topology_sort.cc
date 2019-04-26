/*

Topology Sort  
https://www.acmicpc.net/problem/2252

implemented 
*static edge
*static Queue 
*Topology sort

*/
#include <iostream>
#define VERTEX (int)3e5
#define MAXSIZE (int)5e5 // QUEUE
#define MAXEDGE (int)1e5

using namespace std;

struct EdgeSystem
{
  int id;
  int latestEdge[VERTEX];
  EdgeSystem() 
  {
    id = 0;
    for (int i =0; i<VERTEX; i++) 
    {
      latestEdge[i] = -1;
    }
  }
};

struct Edge
{
  int v;
  int before;
  Edge() { };
  Edge(int v ) : v(v) {};
};

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

struct Topology
{
  int ind[VERTEX], n;
  int ans[VERTEX], ansLen;

  Queue q;
  Edge edge[MAXEDGE];
  EdgeSystem esys;

  Topology()
  {
    for (int i=0; i<VERTEX; i++) ind[i] = 0;
    ansLen = 0;
  }

  void sort()
  {
    for (int i=1; i<=n; i++)
    {
      if (ind[i]==0)  q.push(i); 
    }
    while(!q.empty())
    {
      int now = q.front();
      ans[ansLen++] = now;
      q.pop();

      int edgeId = esys.latestEdge[ now ];
      while( edgeId >= 0 )
      {
        ind[ edge[ edgeId ].v ] --;
        if ( ind[ edge[ edgeId ].v ] == 0) 
        {
          q.push( edge[ edgeId ].v  );
        }
        edgeId = edge[ edgeId ].before;
      }
    }
  }

  int* return_ans() { return ans; }

};

Topology topology;

EdgeSystem esys;
Edge edge[MAXEDGE];

int main()
{
  int n, m;
  cin >> n >> m;

  topology.n = n;

  while(m--)
  {
    int u, v;
    cin >> u >> v;
   
    topology.ind[u]++;

    edge[ esys.id ] = Edge(u);
    edge[ esys.id ].before = esys.latestEdge[ v ];
    esys.latestEdge[ v ] = esys.id;
    esys.id++;
  }

  for (int i=0; i<MAXEDGE; i++) topology.edge[i] = edge[i];
  topology.esys = esys;

  topology.sort();
  int* ans = topology.return_ans();
  for (int i=n-1; i>=0; i--)
  {
    cout << ans[i] << " ";
  }
  cout << "\n";
}
