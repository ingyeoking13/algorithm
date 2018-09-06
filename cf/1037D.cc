#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

pair<int,char> p[(int)2e5+1];
vector<int> e[(int)2e5+1];

char v[(int)2e5+1];
int depth[(int)2e5+1];

int fp(int u)
{
  if (p[u].first == u) return p[u].first;
  else {
    p[u].first = fp(p[u].first);
    return p[u].first;
  }
}

int main()
{
  int n;
  scanf("%d", &n);
  //for (int i=1; i<=n; i++) p[i]=make_pair(i, 0);

  for (int i=0; i<n-1; i++)
  {
    int u, v; scanf("%d %d", &u, &v);
//    p[fp(v)].second = 1;
 //   p[fp(v)].first = fp(u);
    e[u].push_back(v);
    e[v].push_back(u);
  }

  int start=1;
  /*
  for (int i=1; i<=n; i++)
  {
    if (p[i].second == 0) 
    {
      start =i;
      break;
    }
  }
  */
  queue<int> q;
  q.push(start);
  v[start]=1;
  depth[start]=0;

  while(!q.empty())
  {
    int now = q.front(); 
    q.pop();
    for (auto next : e[now])
    {
      if  (v[next]) continue;
      depth[next] = depth[now]+1;
      v[next] =1;
      q.push(next);
    }
  }
  int prev=-1;
  for (int i=0; i<n; i++) 
  {
    int tmp; scanf("%d", &tmp);
    if (depth[tmp] >= prev) prev = depth[tmp];
    else return !printf("No\n");
  }
 printf("Yes\n");
}
