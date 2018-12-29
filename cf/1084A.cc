#include <stdio.h>

int abs(int a) { return a>0?a:-a;}

int main()
{
  int n;
  int a[(int)1e2];

  scanf("%d", &n);
  for (int i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
  }

  int ans= (int)1e9;
  for (int i=0; i<n; i++)
  {
    int x = i;
    int tmp = 0;
    for (int j=0; j<n; j++)
    {
      int cost = a[j]*(abs(x-j)+abs(j)+abs(x));
      tmp += cost;
    }
    if ( ans > tmp) ans = tmp;
  }

  printf("%d\n", ans*2);
}
