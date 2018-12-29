#include <stdio.h>
#include <string.h>

char s[100];

int main()
{
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  int len = strlen(s);

  int jump=0;
  for (int i=0; i<len; i+=jump)
  {
    jump++;
    printf("%c", s[i]);
  }
  printf("\n");

}
