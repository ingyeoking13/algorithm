#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> e[(int)1e4];

int main()
{
  int n, m;
  cin >> n >> m;

  while(m--)
  {
    int u, v;
    cin >> u >> v;
    u--, v--;
    e[v].push_back(u);
  }

  int ans = 0;
  vector<int> cnt(n, 0);
  for (int i=0; i<n; i++) 
  { 
    queue<int> q;
    vector<bool> visit(n, false);
    q.push(i);
    visit[i]= true;

    while(!q.empty())
    {
      int cur = q.front();
      q.pop();

      for (int j=0; j<e[cur].size(); j++)
      {
        int next = e[cur][j];
        if ( visit[next]) continue;
        visit[next] = true;
        q.push(next);
      }
    }

    for (int j=0; j<n; j++)
    {
      if (visit[j]) cnt[i]++;
    }
    if ( ans < cnt[i] )  ans = cnt[i];
  }

  for (int i = 0; i<n; i++)
  {
    if ( cnt[i] == ans) 
      cout << i+1 << " ";
  }
  cout <<"\n";
}