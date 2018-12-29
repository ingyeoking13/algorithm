#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAX 2e8+5e7

using namespace std;
int a[500];
int d[500][501];
int query[500][500];

int cost(int f, int t)
{
  int ret =0;
  int mid = (f+t)/2;
  for (int i=f; i<=t; i++)
  {
    ret += abs(a[i]-a[mid]);
  }
  return ret;
}

int go(int idx, int m)
{
  if ( (idx>=0 && m ==0) || (idx<0 && m>0 )) { return MAX; }
  if (idx==-1 &&  m == 0 ) { return 0; }

  if ( d[idx][m] >=0 ) return d[idx][m];
  if ( d[idx][m] == -1) d[idx][m] = MAX;

  for (int i=idx; i>=0; i--)
  {
     d[idx][m] = min( go(i-1, m-1) + query[i][idx], d[idx][m]);
  }
  return d[idx][m];
}

int main()
{
  int T;
  scanf("%d", &T);


  for (int test= 1; test<=T; test++)
  {
    memset(d, -1, sizeof(d));

    int n, m;
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);

    sort(a,a+n);

    for (int i=0; i<n; i++)
    {
      for (int j=i+1; j<n; j++)
      {
        query[i][j]=cost(i, j);
      }
    }

    printf("Case #%d\n", test);
    printf("%d\n", go(n-1, m)); // 0~ n-1 : a    , m 개로 파티션 하라

  }
}
