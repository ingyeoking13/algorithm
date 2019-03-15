#include <stdio.h>

int cnt[100];
int min(int x, int y) { return x<y?x:y; }
int main()
{
  int n, k;
  scanf("%d%d", &n, &k);

  for (int i=0; i<n; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    cnt[ tmp%k ]++;
  }

  int ans=0;
  for (int i=0; i<=k/2; i++)
  {
    if ( i==0 ) ans += ((cnt[i]/2)*2);
    else
    {
      if ( i == k-i ) ans += ((cnt[i]/2)*2);
      else ans += (min(cnt[i], cnt[k-i])*2);
    }
  }
  printf("%d\n", ans);
}
