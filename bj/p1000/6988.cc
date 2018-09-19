#include <stdio.h>
#include <string.h>

int a[3000];
long long dp[3000][3000];
int map[1000001];
int mapVal=0;
int n;
long long ans=0;

long long max(long long a, long long b) { return  a>b?a:b; }
long long dfs(int now, int cnt, long long sum, int diff)
{
  if (diff != -1 )
  {
    if (dp[now][map[diff]]>=0 )
    {
      return dp[now][map[diff]];
    }
    dp[now][map[diff]]=0;
  }
  printf("now : %d\n", now);

  for (int i=now+1; i<n; i++)
  {
    int nextdiff=diff;

    if (nextdiff==-1)
    {
      nextdiff = a[i]-a[now];
    }
    else if(a[i]-a[now]!=diff)
    {
      continue;
    }

    if (map[nextdiff]==-1)
    {
      map[nextdiff]=mapVal++;
    }

    dp[now][map[nextdiff]] = 0;
    long long tmp=0;
    tmp += dfs(i, cnt+1, sum+a[i], nextdiff);
    printf("%d %lld\n", i, tmp);

    if ( dp[now][map[nextdiff]] < tmp)  dp[now][map[nextdiff]]=tmp;
    if ( ans < dp[now][map[nextdiff]]) ans = dp[now][map[nextdiff]];
  }

  if (diff==-1) return 0;
  return dp[now][map[diff]];
};

int main()
{
  scanf("%d", &n);
  memset(dp,-1, sizeof(dp));
  memset(map,-1, sizeof(map));

  for (int i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
  }

  long long ans=0;
  for (int i=0; i<n; i++)
  {
    for (int j=i+1; j<n; j++)
    {
      ans = max(dfs(i, j, a[j]-a[i], 2), ans);
    }
  }

  printf("%lld\n", ans);
}
