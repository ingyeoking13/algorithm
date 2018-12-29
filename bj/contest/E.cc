#include <stdio.h>

int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
  int curdate = 0;
  
  int tyear;
  scanf("%d", &tyear);

  int ans=0;
  for (int i= 2019; i<=tyear; i++)
  {
    for (int j=0; j<12; j++)
    {
      int yun=0;
      if (i%4 == 0) yun=1;
      if (i%100 == 0) yun=0;
      if (i%400 == 0) yun=1;

      for (int k=1; k<=month[j]; k++)
      {
        curdate++;
        if (curdate >=7 ) curdate=0;
        if (curdate == 4 && k == 13) ans++;
      }

      if ( yun && j==1) 
      {
        curdate++;
        if (curdate >=7 ) curdate=0;
      }

    }
  }
  printf("%d\n", ans);


}
