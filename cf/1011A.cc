#include <stdio.h>
#include <algorithm>

using namespace std;

char s[51];

int go(int now, int len, int cnt, int point)
{
  if ( cnt == 0)
  {
    return point;
  }

  int ret=1e9;
  for (int i=now+1; i<len; i++)
  {
    if ( s[i] - s[now] <=1 ) continue; 

    ret = min(go(i, len, cnt-1, point+(s[i]-'a'+1)), ret);
  }
  return ret;
}


int main()
{

  int n, k; scanf("%d %d", &n, &k);
  scanf("%s", s);
  sort(s, s+n);
  int ans=1e9;

  for (int i=0; i<n; i++)
  {
     ans = min(go(i, n, k-1, s[i]-'a'+1), ans);
  }
  if (ans == 1e9) printf("-1\n");
  else printf("%d\n", ans);

}
