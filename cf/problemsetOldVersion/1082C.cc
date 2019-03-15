#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
  int n, m;
  scanf("%d%d", &n, &m);

  vector<vector<int> > v(m);
  for (int i=0; i<n; i++)
  {
    int s, r;
    scanf("%d%d", &s, &r);
    s--;
    v[s].push_back(-r);
  }

  for (int i=0; i<m; i++)
  {
    sort(v[i].begin(), v[i].end());
  }

  int mxlen =0;
  vector<int> d(1e5, 0);

  for (int i=0; i<m; i++)
  {
    if (v[i].size() == 0) continue;

    for (int j=0; j<v[i].size(); j++) v[i][j] = -v[i][j];

    d[0] += max(0, v[i][0]);
    for (int j=1; j<v[i].size(); j++) 
    {
      v[i][j] = v[i][j-1] + v[i][j];
      d[j] += max(0, v[i][j]); 
    }
  }

  int ans=0;
  for (int i=0; i<1e5; i++) ans = max(ans, d[i]);
  printf("%d\n", ans);
}
