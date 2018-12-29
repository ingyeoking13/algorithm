#include <stdio.h>

int main()
{
  int n, mm;
  scanf("%d%d", &n, &mm);

  int a[(int)1e5];
  for (int i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
  }

  int l = 1, r= 1e9;
  int ans;
  while(l<=r)
  {
    int m = (l+r)/2;

    int now=0;
    int cnt=0, non=0;
    for (int i=0; i<n; i++)
    {
      if (now < a[i])
      {
        now=m;
        cnt++;
        now-=a[i];

        if (now<0) 
        {
          non=1;
          break;
        }
      }
      else now-=a[i];
    }

    if (non==0)
    {
      if ( cnt <= mm )
      {
        ans = m;
        r =m-1;
      }
      else l=m+1;
    }
    else l=m+1;
  }
  printf("%d\n", ans);


}
