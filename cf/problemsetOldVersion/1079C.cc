#include <stdio.h>

int a[(int)1e5];
int cnt[(int)1e5];
int main()
{

  int n; scanf("%d", &n);
  for (int i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
  }

  cnt[0]=0;
  for (int i=1; i<cnt; i++)
  {
    if (a[i] > a[i-1]) cnt[i]= cnt[i-1]+1;
    else if (a[i]== a[i-1]) cnt[i] = cnt[i-1];
    else cnt[i] = cnt[i-1]-1;
  }

  for (int i=0; i<cnt; i++) if (cnt[i] >=5 || cnt[i] <=-5) return !printf("-1\n");


}
