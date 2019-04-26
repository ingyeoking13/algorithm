#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int n;
int d[(int)1e3][(int)1e3];
int a[(int)1e3], b[(int)1e3+1];

int go(int x, int y) 
{
  if ( x ==n || y== n) return 0;
  if ( d[x][y] >=0) return d[x][y];

  int diff = a[x]- b[y];
  if ( diff <0) diff =-diff;
  int ret= 0;

  if (diff <=4 ) 
  {
    ret=go(x+1, y+1)+1;
  }

  ret=max(go(x, y+1), ret);
  ret=max(go(x+1, y), ret);
  return d[x][y]= ret;
}

int main()
{
  scanf("%d", &n);

  for (int i=0; i<n; i++) scanf("%d", &a[i]);
  for (int i=0; i<n; i++) scanf("%d", &b[i]);

  memset(d, -1, sizeof(d));
  int ans=go(0, 0);
  printf("%d\n", ans);

}
