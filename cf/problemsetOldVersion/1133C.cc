#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> a;

int main()
{
  int n;
  scanf("%d", &n);

  a.resize(n);
  for (int i=0; i<n; i++) scanf("%d", &a[i]);
  sort(a.begin(), a.end());

  int l =0, r=0, ans = 1;
  while (r +1 < n && (a[r+1] - a[l] <=5) )
  {
    r++;
    ans++;
  }

  while( true )
  {
    int prevL = a[l];
    int cnt = r-l+1;
    while ( l<n && prevL == a[l] ) l++, cnt--;
    if( l== n ) break;

    while ( r+1<n && (a[r+1] -a[l] <=5 )) r++, cnt++;
    if ( cnt > ans ) ans = cnt;
  }
  printf("%d\n", ans);

}
