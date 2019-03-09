#include <stdio.h>
#include <algorithm>

using namespace std;

pair<int,int> a[(int)2e5];
bool chk[(int)2e5];

bool mycmp(pair<int, int> x, pair<int, int> y)
{
  return x.first > y.first;
}

int main()
{
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i=0; i<n; i++) 
  {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }

  sort(a, a+n, mycmp);

  long long ans=0;
  for (int i=0; i<m*k; i++)
  {
    chk[ a[i].second ] = true; 
    ans += a[i].first;
  }
  printf("%lld\n", ans);

  int cnt = 0;
  for (int i=0; i<n; i++)
  {
    if ( chk[ i ] ) 
    {
      if ( cnt == m ) printf("%d ", i), cnt=0;
      cnt++;
    }
  }

  printf("\n");
}
