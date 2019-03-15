#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
  int n, m , k;
  scanf("%d%d%d", &n, &m, &k);

  int a[(int)2e5];
  for (int i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
  }

  sort(a, a+n);

  int times = m/(k+1);
  long long b = (((long long)a[n-1])*k + a[n-2]); 
  int times_ = m%(k+1);
  long long c = a[n-1];

  long long ans = (long long)b*times + (long long)c*times_;
  printf("%lld\n", ans);

}
