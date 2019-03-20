#include <stdio.h>
#include <math.h>

int x[(int)1e4], y[(int)1e4];
int main()
{
  int n;
  scanf("%d", &n);

  for (int i=0; i<n; i++)
  {
    scanf("%d %d", &x[i], &y[i]);
  }

  for (int i=1; i<n; i++)
  {
    x[i] -= x[0]; y[i] -= y[0];
  }

  double ans =0;
  for (int i=1; i<n-1; i++)
  {
    double tmp = ( ((double)x[i])*y[i+1]  - ((double)x[i+1])*y[i]);
    ans += tmp;
  }
  if (ans <=0) ans = -ans;
  ans/=2;

  printf("%.1lf\n", ans);
}
