#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v[5001];

int main()
{
  int n;
  scanf("%d", &n);

  for (int i=0; i<n; i++)
  {
    int x, col;
    scanf("%d%d",&x, &col);
    v[col].push_back(x);
  }

  for (int i=0; i<=5000; i++)
  {
    sort(v[i].begin(), v[i].end());
  }

  int ans=0;
  for (int i=0; i<=5000; i++)
  {
   if ( v[i].size() <= 1) continue;
   ans += v[i][1] - v[i][0];


   for (int j=1; j<v[i].size()-1; j++)
   {
     int bef = v[i][j] - v[i][j-1];
     int aft = v[i][j+1] - v[i][j];

     int mn = bef>aft?aft:bef;
     ans += mn;

   }
   ans +=(v[i].back() - v[i][v[i].size()-2]);
  }
  printf("%d\n", ans);

}
