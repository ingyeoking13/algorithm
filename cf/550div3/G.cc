#include <stdio.h>

int a[(int)2e5+1];
int tail[(int)2e5+1];
int main()
{
  int n;
  scanf("%d", &n);

  for (int i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
  }
  int len = 1;
  tail[0] =  a[0];

  for (int i=1; i<n; i++)
  {
    if ( a[i] < tail[0] )
    {
      tail[0] = a[i];
    }
    else if ( a[i] > tail[len-1] )
    {
      tail[len] = a[i];
      len++;
    }
    else 
    {
      int l = 0, r = len-1;
      int aa = -1;

      while(l<=r)
      {
        int m = (l+r)/2;
        if ( tail[m] >= v[i] )
        {
          aa = m;
          r=m-1;
        }
        else l=m+1;
      }
      if ( aa >= 0) tail[aa] = v[i];
    }

  }

}
