#include <stdio.h>

int d[(int)1e5+1][4];
int main()
{

  d[0][0]=1;
  for (int i=1; i<=(int)1e5; i++)
  {
    for (int j=1; j<=3; j++)
    {
      for (int k=0; k<4; k++)
      {
        if (j==k) continue;

        if (i-j>=0)
        {
          d[i][j] += d[i-j][k];
          d[i][j]%=((int)1e9+9);
        }
      }
    }
  }

  int n;
  for (scanf("%d",&n); ~scanf("%d", &n); )
  {
    int ans=0;
    for (int i=0; i<4; i++)
    {
      ans+=d[n][i];
      ans%=((int)(1e9+9));
    }
    printf("%d\n", ans);
  }


}
