#include <stdio.h>


int main()
{
  printf("%d\n", (int)1e4);
  for (int i=0; i<1e4; i++)
  {
    printf("%d ", i+1);
  }

}
