#include <iostream>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

char s[1000][32];
int d[1000];
int f[1000];
vector<int> e[1000];
queue<int> q;
int main()
{
  int n, k;
  cin >> n >> k;

  for (int i=0; i<n; i++)
  {
    cin >> s[i];
  }

  for (int i=0; i<n; i++)
  {
    for (int j=i+1; j<n; j++)
    {

      int cnt =0;
      for (int l=0; l<k; l++)
      {
        if ( s[i][l] != s[j][l] )
        {
          cnt++;
        }
      }

      if ( cnt == 1 )
      {
        e[i].push_back(j);
        e[j].push_back(i);
      }
    }
  }

  int s, ee;
  cin >> s >> ee;
  s--, ee--;

  memset(d, -1, sizeof(d));
  memset(f, -1, sizeof(f));

  d[s] = 0;
  q.push(s);

  while( !q.empty() )
  {
    int now = q.front();
    q.pop();

    for (int i=0; i<e[now].size(); i++)
    {
      int next = e[now][i];
      if ( d[ next ] < 0 )
      {
        d[next] = d[now] +1;
        f[next] = now;
        q.push(next);
      }
    }
  }

  if ( f[ee] == -1 ) cout << "-1\n";
  else
  {

    int ans[(int)1e3];
    int len=0;
    int cur = ee;
    while ( cur != -1 )
    {
      ans[len++] = cur+1;
      cur = f[cur];
    }
    for (int i=len-1; i>=0; i-- )
    {
      cout << ans[i] << " ";
    }
    cout << "\n";
  }
}
