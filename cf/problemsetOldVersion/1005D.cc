#include <stdio.h>
#include <string.h>

int main()
{
  char s[(int)2e5+1];
  scanf("%s", s);

  int len = strlen(s);

  long long ans=0, now=0;
  int l=0;
  for (int r=0; r<len; r++)
  {
    if ( (s[r]-'0')%3 ==0) 
    {
      ans++;
      now=0;
      l=r+1;
    }
    else 
    {
      now += s[r]-'0';

      long long tmp = now;
      int tmpl =l;
      while(tmpl<=r)
      {
        if (tmp%3==0) 
        {
          ans++;
          now=0;
          l= r+1;
          break;
        }
        else 
        {
          tmp -= (long long)s[tmpl];
          tmpl++;
        }
      }
    }
  }

  printf("%lld\n", ans);
}
