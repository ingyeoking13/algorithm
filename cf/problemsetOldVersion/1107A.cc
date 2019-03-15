#include <stdio.h>
#include <string.h>

int main()
{
  int T;
  scanf("%d", &T);

  while(T--)
  {
    int n;
    scanf("%d", &n);

    char s[(int)1e3];
    scanf("%s", s);

    int len = strlen(s);

    if ( len >2 )
    {
      printf("YES\n2\n");
      printf("%c %s\n", s[0], s+1);
    }
    else
    {
      if ( s[0] > s[1] )
      {
        printf("YES\n2\n%c %c\n", s[0], s[1]);
      }
      else printf("NO\n");
    }
  }
}
