#include <stdio.h>
#include <string.h>

int main()
{
  int T;
  scanf("%d", &T);

  for (int tt=1; tt<=T; tt++)
  {
    char s[(int)1e5+1];
    scanf("%s", s);

    int len = strlen(s);
    int sz=0;

    long long ans = 0;


    for (int i=0; i<len; i++)
    {
      if (s[i] == '(')
      {
        if ( s[i+1] == ')')
        {
          ans += (long long)sz;
          i++;
        }
        else sz++;
      }
      else 
      {
        ans++; 
        sz--;
      }
    }
    printf("#%d %lld\n", tt, ans);
  }
}
