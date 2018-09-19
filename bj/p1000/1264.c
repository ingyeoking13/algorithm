#include <stdio.h>
#include <string.h>

int main()
{
  while(1)
  {
    char s[300];
    fgets(s, 300, stdin);
    if (s[0] == '#') break;

    int len = strlen(s);
    int cnt=0;
    for (int i=0; i<len; i++)
    {
      if (s[i] == 'i' || s[i] == 'e' || s[i] == 'a' || s[i] == 'o' || s[i] == 'u') cnt++;
      else if ( s[i] == 'I' || s[i] == 'E' || s[i] == 'O' || s[i] == 'U' || s[i] == 'A') cnt++;
    }

    printf("%d\n", cnt);
  }
}
