#include <stdio.h>

using namespace std;
double a[1000], b[1000];

int main()
{
  int n, start;
  scanf("%d %d", &n, &start);
  for (int i=0; i<n; i++) 
  {
    scanf("%lf", &a[i]);
    if ( a[i] == 1) return !printf("-1\n");
  }
  for (int i=0; i<n; i++) 
  {
    scanf("%lf", &b[i]);
    if (b[i] == 1) return !printf("-1\n");
  }

  double before = start*b[0]/(b[0]-1);

  for (int i=n-1; i>0 ;i--)
  {
    before = before*a[i]/(a[i]-1);
    before = before*b[i]/(b[i]-1);
  }
  before = before*a[0]/(a[0]-1);
  printf("%.6lf\n", before-start);

}
