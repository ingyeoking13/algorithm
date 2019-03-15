#include <stdio.h>
#include <string.h>

int a[(int)1e5], d[(int)1e5][2];
int b[(int)1e5], d2[(int)1e5][2];
int max ( int x, int y ) { return x>y?x:y; };
int main()
{
  int T;
  scanf("%d", &T);
  for (int test_case = 1; test_case<=T; test_case++)
  {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i=0; i<n; i++)
    {
      for (int j=0; j<m; j++) scanf("%d", &a[j]);

      d[0][0]=0; 
      d[0][1]=a[0];
      d[1][0] = a[0];
      d[1][1] = a[1];

      for (int j=2; j<m; j++)
      {
        d[j][0]=d[j][1]=0;
        d[j][0] = max( d[j][0], d[j-1][1]); 
        d[j][1] = max( d[j][1], d[j-1][0] + a[j]);
        d[j][1] = max( d[j][1], d[j-2][0] + a[j]);
      }
      b[i] = max( d[m-1][0], d[m-1][1]);
    }

    d2[0][0] = 0;
    d2[0][1] = b[0];

    d2[1][0] = b[0];
    d2[1][1] = b[1];
    for (int i=2; i<n; i++)
    {
      d2[i][0] = d2[i][1] = 0;
      d2[i][0] = max( d2[i][0], d2[i-1][1] );
      d2[i][1] = max( d2[i][1], d2[i-1][0] + b[i]);
      d2[i][1] = max( d2[i][1], d2[i-2][0] + b[i]);
    }

    printf("#%d %d\n", test_case, max(d2[n-1][0], d2[n-1][1]));
  }
}
