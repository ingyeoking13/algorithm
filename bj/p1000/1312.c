#include <stdio.h>

int main()
{
  int a, b, n; scanf("%d %d %d", &a, &b, &n);
  a%=b;
  int ans=0;
  for (int i=0; i<n; i++)
  {
    a*=10;
    ans= a/b;
    a%=b;
  }
  printf("%d\n", ans);

}
