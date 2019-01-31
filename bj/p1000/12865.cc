#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int w[(int)1e2];
int v[(int)1e2];
int score[(int)1e5+1];
int main()
{
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i=0; i<n; i++)
  {
    scanf("%d%d", &w[i], &v[i]);
  }
  memset(score, -1, sizeof(score));
  score[0]=0;

  for (int i=0; i<n; i++)
  {
    for (int j=1e5; j>=0; j--)
    {
      if (score[j] <0 ) continue;
      if ( w[i] + j > k ) continue;

      score[w[i] + j] = max(score[w[i] +j], score[j]+v[i]);
    }
  }

  int ans=0;
  for (int i=0; i<=k; i++)
  {
    ans = max(score[i], ans);
  }
  printf("%d\n", ans);
}
