#include <stdio.h>

int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
  {
    int n, x, y, d;
    scanf("%d%d%d%d", &n, &x, &y, &d);

    int ans=1e9+9;
    if ( y>x && ((y-x)%d == 0))
    {
      ans = (y-x)/d;
    }
    else if ( y<=x && ((x-y)%d == 0))
    {
      ans = (x-y)/d;
    }
    else if ( ((y-1)%d == 0) && ((n-y)%d==0))
    {
      int a = (y-1)/d + (x-1)/d + ((x-1)%d?1:0);
      int b = (n-y)/d + (n-x)/d + ((n-x)%d?1:0);

      ans = (a>b?b:a);
    }
    else if ( (y-1)%d == 0)
    {
      ans = (y-1)/d + (x-1)/d + ((x-1)%d?1:0);
    }
    else if ( (n-y)%d==0)
    {
      ans = (n-y)/d + (n-x)/d + ((n-x)%d?1:0);
    }
    printf("%d\n",((ans==1e9+9)?-1:ans));
    
  }
}
