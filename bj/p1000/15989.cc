#include <stdio.h>

int d[10001];
int main()
{
  d[0]=1;

  for (int i=1; i<=3; i++)
  {
    for (int j=1; j<=10000; j++)
    {
      if (j-i >= 0)
      {
        d[j] += d[j-i];
      }
    }
  }

  int n;
  for (scanf("%d", &n); ~scanf("%d", &n); printf("%d\n",d[n]));

}
