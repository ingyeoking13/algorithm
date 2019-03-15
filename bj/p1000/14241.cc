#include <stdio.h>

int a[100];
int main()
{
  int n;
  scanf("%d", &n);

  for(int i=0;i<n;i++) scanf("%d", &a[i]);

  int ans =0;
  int prev = a[0];

  for (int i=1; i<n; i++)
  {
    ans += (prev*a[i]);
    prev = (prev+a[i]);
  }
  printf("%d\n", ans);

}
