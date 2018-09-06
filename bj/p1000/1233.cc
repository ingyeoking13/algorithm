#include <stdio.h>

int cnt[20+20+40+1];
int main()
{
  int a, b, c; scanf("%d %d %d", &a, &b, &c);

  for (int i=1; i<=a; i++)
  {
    for (int j=1; j<=b; j++)
    {
      for (int k=1; k<=c; k++)
      {
        cnt[i+j+k]++;
      }
    }
  }

  int mxcnt=0, ans;
  for (int i=0; i<=80; i++)
  {
    if (mxcnt < cnt[i] ) 
    {
      ans =i;
      mxcnt = cnt[i];
    }
  }
  printf("%d\n", ans);

}
