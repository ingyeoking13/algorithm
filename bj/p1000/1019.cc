#include <stdio.h>

int ans[10];

void calc(int n)
{
  int l =1;
  int r =n;
  int base = 1;

  while (l <=r )
  {
    while ( r%10 != 9 && l<=r )
    {
      int tmp = r;
      while(tmp)
      {
        ans[tmp%10] += base;
        tmp/=10;
      }
      r--;
    }

    if ( r< l ) break;

    while( l%10 != 0 && l<=r )
    {
      int tmp = l;
      while(tmp)
      {
        ans[tmp%10] += base;
        tmp/=10;
      }
      l++;
    }

    l/=10; r/=10;

    for (int i=0; i<10; i++)
    {
      ans[i] += (r-l+1)*base;
    }

    base*=10;
  }
}

int main()
{
  int n;
  scanf("%d", &n);

  calc(n);
  for (int i=0; i<10; i++) 
    printf("%d ",ans[i]);
  printf("\n");

}
