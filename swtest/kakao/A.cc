#include <stdio.h>

int main()
{

  int a[6] = { 1, 2, 3, 4, 5, 6};
  int b[5] = { 1, 2, 4, 8, 16};
  int moneyA[6] ={
    5000000, 3000000, 2000000, 500000, 300000, 100000
  };
  int moneyB[5] = {
    5120000, 2560000, 1280000, 640000, 320000
  };

  int T;
  scanf("%d", &T);
  while(T--)
  {
    int x, y;
    scanf("%d %d", &x, &y);

    int ans=0;
    int i=0;
    for ( i=0; x>0; i++) x-= a[i];
    i--;
    if (i>=0) ans += moneyA[i];

    for ( i=0; y>0; i++) y-= b[i];
    i--;
    if (i>=0 ) ans += moneyB[i];

    printf("%d\n", ans);
  }


}
