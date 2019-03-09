#include <stdio.h>

int main()
{
  freopen("in.txt", "w", stdout);
  printf("5000 5000\n");
  for (int i=0; i<5000; i++)
     printf("1 ");
  printf("\n");

}
