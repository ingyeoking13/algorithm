#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int> > e;
vector<bool> visit;
vector<bool> pqIn;
priority_queue<int> pq;

void go(int now)
{
  visit[now]=true;

  printf("%d ", now);
  pq.pop();

  for( auto v : e[now] )
  {
    if ( visit[v] ) continue;
    if ( pqIn[v] ) continue;
    pq.push(-v);
    pqIn[v] = true;
  }

  while ( !pq.empty() )
  {
    int next = pq.top();
    next = -next;
    if (visit[next] ) pq.pop();
    else go(next);
  }

}

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  e.resize(n+1);
  visit.resize(n+1, false);
  pqIn.resize(n+1, false);

  while(m--)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    e[u].push_back(v);
    e[v].push_back(u);
  }

  pq.push(1);
  pqIn[1] = true;
  go(pq.top());
  printf("\n");
}
