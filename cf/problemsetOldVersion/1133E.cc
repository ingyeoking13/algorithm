#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int d[5000][5001];
int a[5000];
int n, k;

int go(int idx, int part)
{
  if( idx == -1 ) return 0;
  if( part == 0 ) return d[idx][part]= 0;

  if ( d[idx][part] >=0) return d[idx][part];

  d[idx][part]= 0;

  for (int i=idx; i>=0; i--)
  {
    int start = i;
    if( a[idx] - a[start] <=5 ) 
    {
      d[idx][part] = max( d[idx][part], go(start-1, part-1)+ idx-start+1);
    }
    else break;
  }

  d[idx][part] = max(d[idx][part], go(idx-1, part));
  return d[idx][part];

}

int main()
{
  int n, k;
  scanf("%d%d", &n, &k);

  for (int i=0; i<n; i++) scanf("%d", &a[i]);
  memset(d, -1, sizeof(d));

  sort(a, a+n);
  printf("%d\n", go(n-1, k));

}
