#include <stdio.h>

int a[(int)2e5];
int pre[(int)2e5][2];
int main()
{
  int n;
  scanf("%d", &n);

  for (int i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
  }

  pre[0][0] = a[0];
  pre[1][1] = a[1];
  for (int i=2; i<n; i++)
  {
    if ( i%2 == 0) pre[i][1] = pre[i-1][1];
    else pre[i][1] = pre[i-1][1]+ a[i];
  }

  for (int i=1; i<n; i++)
  {
    if ( i%2 == 1) pre[i][0] = pre[i-1][0];
    else pre[i][0] = pre[i-1][0]+ a[i];
  }

  int ans =0;
  int one = pre[n-1][0] -pre[0][0];
  int two = pre[n-1][1] -pre[0][1];

  if ( one == two) ans++;
  for (int i=1; i<n; i++)
  {
    int one = pre[n-1][0] -pre[i][0] + pre[i-1][1]; 
    int two = pre[n-1][1] -pre[i][1] + pre[i-1][0];
    if (one == two) ans++;
  }
  printf("%d\n", ans);
}
