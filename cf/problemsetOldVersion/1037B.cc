#include <stdio.h>
#include <algorithm>

using namespace std;

int a[(int)2e5];
int main()
{
  int n, m;
  scanf("%d %d", &n, &m);

  for (int i=0; i<n; i++) scanf("%d", &a[i]);
  sort(a, a+n);

  long long ans=0;
  if (a[n/2] == m);
  else if (a[n/2] <m)
  {

    for (int i=n/2; i<n; i++)
    {
      if ( a[i] < m)
      {
        ans += (long long)(m-a[i]);
      }
      else break;
    }

  }
  else
  {
    for (int i= n/2; i>=0; i--)
    {
      if (a[i] >m)
      {
        ans += (long long)(a[i]-m);
      }
      else break;
    }
  }
  printf("%lld\n", ans);

}
