#include <stdio.h>
#include <string.h>

int main()
{
  int a, b;
  char c[105];
  scanf("%d%d%s", &a, &b, c);
  int len = strlen(c);

  if ((c[len-1]-'0')%2==1) printf("%d\n", a^b);
  else printf("%d\n", a);
}
