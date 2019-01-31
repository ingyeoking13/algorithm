#include <stdio.h>

int a[11];
int oper[4];

int mx=-1e9-1;
int mn=+1e9+1;

void go(int now, int mxlen, int sum, int sub, int mul, int div, int val)
{
  if (now==mxlen)
  {
    if(val>mx) mx =val;
    if(val<mn) mn = val;
    return;
  }

  if (sum >0) go(now+1, mxlen, sum-1, sub, mul, div, val+a[now]);
  if (sub >0) go(now+1, mxlen, sum, sub-1, mul, div, val-a[now]);
  if (mul >0) go(now+1, mxlen, sum, sub, mul-1, div, val*a[now]);
  if (div >0) go(now+1, mxlen, sum, sub, mul, div-1, val/a[now]);
}

int main()
{
  int n;
  scanf("%d", &n);

  for (int i=0; i<n; i++) scanf("%d", &a[i]);
  for (int i=0; i<4; i++) scanf("%d", &oper[i]);

  int val =0;
  go(1, n, oper[0], oper[1], oper[2], oper[3], a[0]);
  printf("%d\n%d\n", mx, mn);
}
