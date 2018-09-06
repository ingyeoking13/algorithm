#include <stdio.h>

int main()
{

  int n, m, M, T, R;
  scanf("%d %d %d %d %d", &n, &m, &M, &T, &R);

  int now =m;
  int ans=0, exercnt=0;

  while(1)
  {
    if (now + T > M ) 
    {
      // substract min exercise
      int minNeedR = T-M+now;
      if ( now -minNeedR < m)
      {
        return !printf("-1\n");
      }
      else
      {
        int breakTime = minNeedR/R + minNeedR%R?1:0;
        ans += breakTime;
        now -= breakTime*R;
      }
    }
    else 
    {
      // do exercise
      ans++;
      exercnt++;
      now += T;
    }
    printf("cnt : %d  now : %d time: %d\n", exercnt, now, ans);
    if (exercnt == n) break;
  }
  printf("%d\n", ans);

}
