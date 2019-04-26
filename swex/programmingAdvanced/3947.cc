#include <iostream>
using namespace std;

struct edge
{
  int u, v, w;
  int before;
  edge () {};
  edge(int u , int v, int w) : u(u), v(v), w(w) {};
};

struct node
{
  int u; 
  long long dist;
  node() {};
  node(int u, long long dist) : u(u), dist(dist) { };
};

struct priority_queue
{
  node array[(int)1e7];
  int len; 
  priority_queue() : len(0) {};

  void push(node a) 
  {
    array[len++] = a; 
    swap(0, len-1);
    heapify(0);
  }
  node top() { return array[0]; }
  void pop() 
  {
    swap(0, len-1);
    len--; 
    heapify(0);
  }

  void swap(int i, int j)
  {
    node tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
  }

  void heapify(int i)
  {
    int mx = i;
    int left = (i<<1)+1;

    if ( left < len && array[mx].dist < array[left].dist ) mx = left;

    int right = (i<<1)+2;
    if ( right < len && array[mx].dist < array[right].dist ) mx = right;

    if ( mx != i ) 
    {
      swap(i, mx);
      heapify(mx);
    }
  }

  bool empty() { return len == 0; }
};

struct data 
{
  int user, id;
  bool used;
  data(int x, int y ) : user(x), id(y) {};
  data() {};
};

edge eId[(int)1e6]; 

int latestEdge[(int)2e5+1];
long long d[(int)2e5+1];
int idx=0;
priority_queue pq; 

int usedIdx[(int)2e5+1];
 
int main()
{
  int T;
  int tt = 0;
  cin >> T;
  while (++tt <= T )
  {
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; i++) latestEdge[i] = -1;
    idx =0;

    while(m--)
    {
      int u, v, w;
      cin >> u >> v >> w;

      eId[idx] = edge(u, v, w);
      eId[idx].before = latestEdge[u];
      latestEdge[u] = idx;

      idx++; 
      myElen[u]++; 

      eId[idx] = edge(v, u, w);
      eId[idx].before = latestEdge[v];
      latestEdge[v] = idx;
      
      idx++; 
      myElen[v]++;
    }

    for (register int i=1; i<=n; i++) d[i]= 2e15;
    pq.push(node(1, 0));
    d[1] = 0;

    while(!pq.empty())
    {
      node cur = pq.top();
      int now = cur.u;
      long long dist = -cur.dist;
      pq.pop();

      if ( d[now] <  dist ) continue;

      int key = latestEdge[now];
      while(key >= 0)
      {
        edge ee = eId[key];
        int next = ee.v;
        long long nextDist = dist + ee.w;

        if ( d[next] > nextDist ) 
        {
          usedIdx[next] = key;
          d[next] = nextDist;
          pq.push(node(next, -nextDist));
        }
        else if ( d[next] == nextDist)
        {
          int tmpidx = usedIdx[next];
          int prev = eId[tmpidx].u;
          
          if ( d[now] > d[prev] ) usedIdx[next] = key;
        }
        key = eId[key].before;
      }
    }

    long long ans = 0;
    for (register int i=2; i<=n; i++) 
    {
      ans += (long long)eId[usedIdx[i]].w;
    }
    cout << "#" << tt << " " << ans << "\n";
  }
}
