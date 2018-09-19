#include <stdio.h>

int d[(int)1e6+1];
int main()
{
  int T;
  scanf("%d", &T);
  d[0]=1;

  for(int i=1; i<=(int)1e6; i++)
  {
    for (int j=1; j<=3; j++)
    {
      if ( i-j >= 0)
      {
        d[i] += d[i-j];
        d[i] %= ((int)1e9+9);
      }
    }
  }

  int n;
  for (;~scanf("%d", &n);printf("%d\n", d[n]));
}
