#include <stdio.h>
#include <algorithm>
#include <math.h>

int a[500];
double mean[500];
double ans=100;
int main()
{
  int n, k; scanf("%d %d", &n, &k);

  for (int i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
  }


  for (int i=0; i<n; i++)
  {
    double tmp=0;
    if (i+k-1 >= n ) break;

    for (int j=0; j<k; j++)
    {
      tmp += a[i+j];
    }

    mean[i] = tmp/k;
  }

  for (int i=0; i<n; i++)
  {
    if (i+k-1 >= n) break;

    double tmp=0;
    for (int j=0; j<k; j++)
    {
      tmp += (a[i+j] - mean[i])*(a[i+j] - mean[i]);
    }
    tmp /= k;

    tmp = sqrt(tmp);

    if ( ans > tmp)  ans = tmp;
  }
  printf("%.6lf\n", ans);

}
