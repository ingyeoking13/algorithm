#include <stdio.h>
#include <string.h>

int cnt[26];
char ans[26];

int main()
{
  char s[5001];
  int max =0;
  int anscnt=0;
  while(fgets(s, 5000, stdin))
  {
    int len = strlen(s);
    for (int i=0; i<len; i++)
    {
      if ( 'a' <= s[i] &&  s[i] <='z' )
      {
        cnt[s[i]-'a']++;
      }
    }
  }

  for (int i=0; i<26; i++)
  {
    if (max < cnt[i]) 
    {
      max = cnt[i];
    }
  }

  for (int i=0; i<26; i++)
  {
    if ( cnt[i] == max)
    {
      ans[anscnt++] = 'a'+i;
    }
  }

  for (int i=0; i<anscnt; i++)
  {
    printf("%c", ans[i]);
  }
  printf("\n");


}
