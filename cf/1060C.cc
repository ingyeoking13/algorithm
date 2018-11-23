#include <stdio.h>

int a[2000], b[2000];
int arr[2000][2000];
int pre_arr[2000][2000];
int main()
{
  int n, m, x;
  scanf("%d%d", &m, &n);
  for (int i=0; i<n; i++) scanf("%d", &a[i]);
  for (int i=0; i<m; i++) scanf("%d", &b[i]);
  scanf("%d", &x);

  for (int i=0; i<n; i++)
  {
    for (int j=0; j<m; j++)
    {
      arr[i][j] = a[i]*b[j];
    }
  }

  for (int i=0; i<n; i++)
  {
    pre_arr[i][0] = arr[i][0];
    for (int j=1; j<m; j++)
    {
      pre_arr[i][j] = pre_arr[i][j-1] + arr[i][j];
    }
  }

  for (int i=0; i<n; i++)
  {
    for (int j=0; j<m; j++)
    {
      int l=j, r = m-1;
      while(l<r)
      {
        int mid = (l+r)/2;
        if ( 

      }

    }
  }






}
