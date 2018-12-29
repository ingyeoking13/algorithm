#include <stdio.h>
#include <string.h>

char p[10001], happy[10001];
int func(int a)
{
  int ret = 0;
  while(a) { ret += (a%10)*(a%10); a/=10; }
  return ret;
}

int main()
{
  int T;
  scanf("%d", &T);

  for (int i=2; i<=10000; i++)
  {
    if ( !p[i] )
    {
      for (int j=i +i ; j<=1e4; j+=i) p[j] = 1;

      char visit[10001];
      memset(visit, 0, sizeof(visit));

      int now = i;
      visit[now] =1;

      while(now!=1)
      {
        now = func(now);
        if ( visit[now] ) break;
        visit[now] = 1;
      }
      if (now == 1) happy[ i ]=1;
    }
  }

  for (int i=1; i<=T; i++)
  {
    int n;
    scanf("%d", &n);
    scanf("%d", &n);
    printf("%d %d ", i, n);
    if ( happy[n] ) printf("YES\n");
    else printf("NO\n");
  }
}
