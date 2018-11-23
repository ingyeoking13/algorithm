#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
int main()
{
  int n, m;
  scanf("%d%d", &n, &m); 
  vector<int> e[20000];

  while(m--)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    e[u].push_back(v);
    e[v].push_back(u);
  }

  vector<int> d(n, 2e4+1);
  queue<int> q;
  q.push(0);
  d[0]=0;

  while(!q.empty())
  {
    int now = q.front();
    q.pop();
    for (auto i : e[now])
    {
      if (d[i] == 2e4+1)
      {
        d[i] = d[now]+1;
        q.push(i);
      }
    }
  }

  int ans =1, ans2 = d[0], ans3 = 0;
  for (int i=1; i<n; i++)
  {
    if (d[i] == 2e4+1) continue;

    if (ans2 < d[i]) 
    {
      ans = i+1;
      ans2 = d[i];
      ans3 = 1;
    }
    else if (ans2 == d[i]) ans3++; 
  }
  printf("%d %d %d\n", ans, ans2, ans3);
}
