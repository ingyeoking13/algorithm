#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int a[102];
vector<int> v;
int main()
{
  int n, m, l;
  scanf("%d%d%d", &n, &m, &l);

  a[0] = 0;
  for (int i=1; i<=n; i++)
  {
    scanf("%d", &a[i]);
  }
  a[n+1] = l;

  sort(a, a+n+2);

  for (int i=1; i<=n+1; i++) { v.push_back(a[i]-a[i-1]); }
  sort(v.begin(), v.end());

  int ans=v.back();
  int lb = 1, ub = v.back();

  while(lb<=ub)
  {
    int tmp=0;
    for (int i=0; i<v.size(); i++)
    {
      tmp += v[i]/lb+ (v[i]%lb==0?-1:0);
    }
    if ( ans > lb && tmp<= m) ans = lb;
    lb++;
  }

  printf("%d\n", ans);
}
