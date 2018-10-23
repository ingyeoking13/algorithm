#include <stdio.h>
#define MOD 1000000009

int d1[100001], d2[100001];
int main()
{
  d1[0]=1;

  for (int i=1; i<=100000; i++)
  {
    for (int j=1; j<=3; j++)
    {
      if ( i-j >=0 )
      {
        d1[i] += d1[i-j]%MOD;
        d1[i]%=MOD;
      }
    }
  }

  for (int i=1; i<=100000; i++)
  {
    if ( i%2 == 0)
    {
      d2[i] = d1[i/2];
      if (i-2>=0)
      {
        d2[i] += d1[(i-2)/2];
      }
      d2[i]%=MOD;
    }
    else
    {
      for (int j=1; j<=3; j++)
      {
        if (j==2) continue;
        if (i-j >=0 )
        {
          d2[i] += d1[(i-j)/2];
          d2[i]%= MOD;
        }
      }
    }
  }
  int T;
  scanf("%d", &T);
  while(T--)
  {
    int n; scanf("%d", &n);
    printf("%d\n", d2[n]);
  }
}
