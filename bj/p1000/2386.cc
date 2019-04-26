#include <stdio.h>
#include <string.h>

int main()
{
  while(1)
  {
    char c[2];
    char str[253];

    scanf("%s", c);
    if ( c[0]=='#') break;
    fgets(str, 253, stdin);
    int len = strlen(str);

    int ans=0;
    for (int i=0; i<len ;i++)
    {
      if ( str[i] >= 'A' && str[i] <= 'Z' )
      {
        str[i] -='A';
        str[i] +='a';
      }

      if ( str[i] == c[0] )
      {
        ans++;
      }
    }
    printf("%c %d\n", c[0], ans);
  }
}
