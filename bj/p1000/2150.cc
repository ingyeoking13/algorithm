#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
vector<bool> visit;
vector<vector<int>> edge;
vector<vector<int>> edge_Transpose;
stack<int> st;
vector<vector<int>> component;

void dfs_for_G(int now)
{
  visit[now]=true;
  for (auto to : edge[now])
  {
    if (!visit[to]) 
    {
      dfs_for_G(to);
    }
  }
  st.push(now);
}

void dfs_for_GT(int now, int ans)
{
  visit[now]=true;
  component[ans].push_back(now);

  for (auto to : edge_Transpose[now])
  {
    if (!visit[to])
    {
      dfs_for_GT(to, ans);
    }
  }
}

int main()
{
  int n, m;
  scanf("%d %d", &n,  &m);

  visit.resize(n+1);
  edge.resize(n+1);
  edge_Transpose.resize(n+1);
  component.resize(n); // maximum component size can be "n".

  while(m--)
  {
    int u, v;
    scanf("%d %d", &u, &v);

    edge[u].push_back(v);
    edge_Transpose[v].push_back(u);
  }

  for (int i=1; i<=n; i++)
  {
    if (!visit[i])
    {
      dfs_for_G(i);
    }
  }

  fill(visit.begin(), visit.end(), false);

  int ans=0;
  while(!st.empty())
  {
    int now = st.top();
    st.pop();
    if (!visit[now])
    {
      dfs_for_GT(now, ans);
      ans++;
    }
  }

  printf("%d\n", ans);

  // 문제의 조건에 맞게 정렬 해주는 부분 (SCC 와는 별개)
  for (int i=0; i<ans; i++)
  {
    sort(component[i].begin(), component[i].end());
  }
  sort(component.begin(), component.begin()+ans, 
      [](vector<int> a, vector<int> b) { return a[0]<b[0]; });
  // 정렬 끝

  for (int i=0; i<ans; i++)
  {
    for (auto j : component[i])
    {
      printf("%d ", j);
    }
    printf("-1\n");
  }
}
