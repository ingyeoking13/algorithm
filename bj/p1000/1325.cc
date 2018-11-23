#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

vector<int> e[(int)1e4+1];

int main()
{
  int n , m;
  scanf("%d%d", &n, &m);

  while(m--)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    e[v].push_back(u);
  }

  int mx=0;
  vector<int> ans;

  for (int i=1; i<=n; i++)
  {
    vector<bool> v(n+1, false);
    queue<int> q;
    q.push(i);
    v[i]=true;

    int cnt=0;
    while(!q.empty())
    {
      int now = q.front();
      q.pop();
      cnt++;

      for (auto i : e[now])
      {
        if ( v[i] ) continue;
        v[i]=true;
        q.push(i);
      }
    }

    if (cnt > mx) {
      mx = cnt;
      ans.clear(); 
      ans.push_back(i);
    }
    else if (cnt == mx)
    {
      ans.push_back(i);
    }
  }
  sort(ans.begin(), ans.end());
  for (auto i: ans) printf("%d ", i);
  printf("\n");
}

