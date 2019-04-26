#include <stdio.h>

int a[(int)2e5];
int main()
{
  int n;
  scanf("%d", &n);

  for (int i=0; i<n; i++) scanf("%d", &a[i]);

  long long ans=a[n-1];
  int bef = a[n-1];

  for (int i=n-2; i>=0; i--)
  {
    int cur = a[i];
    if(cur >= bef ) cur = bef-1;
    if(cur < 0) cur = 0;
    ans += cur;
    bef = cur;
  }
  printf("%lld\n", ans);
}
