#include <stdio.h>

int d[100001];
int main()
{

  d[0]=1;

  for (int i=1; i<=1e5; i++)
  {
    for (int j=0; j<=3; j++)
    {
      if (i-j >= 0)
      {
        if ( i-j== 0)
        {
          d[i] += d[0];
        }
        else if ( (i-j)%2==0)
        {
          {
            d[i] += d[(i-j)/2];
            d[i]%= (int)(1e9+9);
          }
        }
      }
    }
  }
  int T;
  scanf("%d", &T);
  while(T--)
  {
    int n;
    scanf("%d", &n);
    printf("%d\n", d[n]);
  }

}
