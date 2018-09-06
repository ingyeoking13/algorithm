#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <time.h>
using namespace std;

int a[1000];
int n, m;

int rem[1000];
long long dp[1000][1000];
long long go(int block, int part, int len)
{

  if (block == n)
  {
    return -(long long)rem[part-1]*rem[part-1];
  }

  if (dp[block][part]>=0) return dp[block][part];

  //printf("%d %d %d\n", block, part, len);

  dp[block][part]=1LL<<60;

  int i=0;
  while(block+i<n && len >= a[block+i]) 
  {
    len -= a[block+i];
    i++;
    rem[part] = len;

    dp[block][part] = min(go(block+i, part+1, m)+(long long)rem[part]*rem[part], dp[block][part]);
    len-=1;
  }

  return dp[block][part];
}

int main()
{
  clock_t start = clock();
  scanf("%d %d", &n, &m);
  for (int i=0; i<1000; i++)
    for (int j=0; j<1000; j++)
      dp[i][j]=-1;

  for (int i=0; i<n; i++) scanf("%d", &a[i]);
  dp[0][0] = go(0, 0, m);
  printf("%lld\n", dp[0][0]);
  clock_t end = clock();
  printf("%lf\n", (double)end- start);
}
