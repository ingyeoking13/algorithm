#include <stdio.h>
#include <algorithm>

using namespace std;
int cnt[101];
int main()
{
  int n, k, mx=0;
  scanf("%d%d", &n, &k);
  for (int i=0; i<n; i++) {
    int tmp;
    scanf("%d",&tmp);
    cnt[tmp]++;

    mx = max(mx, cnt[tmp]);
  }

  int desired_cnt = mx/k + (mx%k?1:0);
  desired_cnt *= k;

  int ans=0;
  for (int i=1; i<=100; i++)
  {
    if (cnt[i] ==0) continue;
    ans += (desired_cnt-cnt[i]);
  }
  printf("%d\n", ans);
}
