#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int> > house;
vector<pair<int, int> > chicken;
vector<bool> use;
int ans=2e9;

void go ( int depth, int cnt, int mx )
{
  if (cnt > mx) return;

  if (depth == use.size()) 
  {
    if (cnt != mx ) return;

    int cost=0;
    for (int i=0; i<house.size(); i++)
    {
      int mn = 1e9;

      for (int j=0; j<chicken.size(); j++)
      {
        if ( use[j] == 0 ) continue;

        auto hpos = house[i];
        auto cpos = chicken[j];

        int cx = cpos.first, cy = cpos.second;
        int hx = hpos.first, hy = hpos.second;

        int tmp = abs(cx - hx) + abs(cy - hy);
        mn = min(tmp, mn);
      }

      cost += mn;
    }

    ans = min(ans, cost);
    //printf("%d\n", ans);

    return;
  }

  use[depth] = 1;
  go( depth+1, cnt+1, mx);
  use[depth] = 0;

  go( depth+1, cnt, mx);
}

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);

  for (int i=1; i<=n; i++)
  {
    for (int j=1; j<=n; j++)
    {
      int tmp;
      scanf("%d", &tmp);

      if (tmp == 1) house.push_back({i, j});
      else if ( tmp == 2) chicken.push_back({i, j});
    }
  }

  use.resize(chicken.size(), false);
  go( 0, 0, m );
  printf("%d\n", ans);
}
