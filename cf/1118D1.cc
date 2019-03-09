#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int a[(int)2e5];
int main()
{
  int n, k;
  scanf("%d %d", &n, &k);

  for (int i=0; i<n; i++) 
  {
    scanf("%d", &a[i]);
    a[i] =-a[i];
  }

  sort(a, a+n);

  for (int i=0; i<n; i++) 
  {
    a[i] =-a[i];
  }

  long long sum=0;
  for (int i=0; i<n; i++)
  {
    sum += a[i];
  }

  if (sum < k) return !printf("-1\n");
  int l=1, r = n;

  int ans=-1;
  while(l<=r)
  {
    int m = (l+r)/2;

    int p=0;
    long long sum =0;
    for (int i=0; i<n; i++)
    {
      if (i%m == 0) p++;
      sum += max(0,a[i]-p+1);
    }
    if (sum >= k)
    {
      ans = m;
      r = m-1;
    }
    else l = m+1;
  }
  printf("%d\n", ans);
}
