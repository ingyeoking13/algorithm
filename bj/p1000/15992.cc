#include <stdio.h>

int d[(int)1e3+1][1001];
int main()
{

  d[0][0]=1;
  for (int i=1; i<=(int)1e3; i++)
  {
    for (int j=1; j<=3; j++)
    {
      for (int k=1; k<=1e3; k++)
      {
        if (i-j>=0)
        {
          d[i][k] += d[i-j][k-1];
          d[i][k]%=((int)1e9+9);
        }
      }
    }
  }

  int n, m;
  for (scanf("%d",&n); ~scanf("%d %d", &n, &m); printf("%d\n", d[n][m]));
}
