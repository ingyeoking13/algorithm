#include <stdio.h>

int cnt[101];
int main()
{
  int n;
  scanf("%d", &n);
  int mx=0;
  while(n--)
  {
    int r;
    scanf("%d", &r);

    for (int i=0; i<r; i++)
    {
      int tmp;
      scanf("%d", &tmp);
      cnt[tmp]++;
      if (mx < cnt[tmp]) mx = cnt[tmp];
    }
  }

  for (int i=1; i<=100; i++)
  {
    if (mx == cnt[i]) printf("%d ", i);
  }
  printf("\n");

}
