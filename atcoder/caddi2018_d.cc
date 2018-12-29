#include <stdio.h>

int a[(int)1e5];

char go(int turn)
{


}


int main()
{
  int n;
  scanf("%d", &n);
  for (int i=0; i<n; i++) 
  {
    scanf("%d", &a[i]);
    if (a[i]%2 == 1) 
    {
      printf("first\n");
      return 0;
    }
  }
  printf("second\n");
  return 0;

  /*
  if(go(1))
  {
    printf("first\n");
  }else printf("second\n");
  */

  if (n ==1 )
  {
    if ( a[0]%2 == 0) printf("second\n");
    else printf("first\n");
  }
  else printf("first\n");

}
