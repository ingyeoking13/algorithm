#include <stdio.h>

int cnt[5];
int main()
{
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i=0; i<n; i++)
  {
    int sex, grade;
    scanf("%d %d", &sex, &grade);
    if (1<= grade  && grade <=2) cnt[0]++;
    else if (3<= grade && grade <=4)
    {
      if( sex == 0) cnt[1]++;
      else cnt[2]++;
    }
    else if (5<= grade && grade <= 6)
    {
      if (sex== 0) cnt[3]++;
      else cnt[4]++;
    }
  }
  int ans=0;
  for (int i=0; i<5; i++)
  {
    while(cnt[i]>0)
    {
      cnt[i]-=k;
      ans++;
    }
  }
  printf("%d\n", ans);

}
