#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int d[(int)1e4+1];
int main()
{

  int n, possible;
  scanf("%d%d", &n, &possible);

  vector<pair<int, int> > v;
  for (int i=0; i<n; i++)
  {
    int kg, happy, cnt;
    scanf("%d%d%d", &kg, &happy, &cnt);

    for (int j=1; cnt>0; j<<=1)
    {
      j = min(j, cnt);
      if ( j* kg > possible) break;

      v.push_back( {j * kg, happy*j });
      cnt -= j;
    }
  }

  memset(d, -1, sizeof(d));
  d[0]=0;

  for (int i=0; i<v.size(); i++) // - > 1e4 // kind
  {
    for (int j=1e4; j>=0; j--) // -> 1e4 // weight
    {
      auto now = v[i];
      int kg = now.first;
      int happy = now.second;

      if (  j - kg < 0) continue;
      if ( d[ j - kg ] < 0) continue;

      d[ j ] = max ( d[j], d[j - kg] + happy);
    }
  }

  int ans=0;
  for (int i=0; i<=possible; i++)
  {
    if ( ans < d[i] ) ans = d[i];
  }
  printf("%d\n", ans);
}
