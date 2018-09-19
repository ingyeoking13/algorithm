#include <stdio.h>
#include <string.h>

int cnt[26];
char s[100005];
int main()
{
  int n;
  scanf("%d", &n);
  while(n--)
  {
    memset(cnt, 0, sizeof(cnt));

    scanf("%s", s);
    int len = strlen(s);

    int chk=0;
    for (int i = 0; i<len; i++)
    {
      cnt[s[i]-'A']++;
      if ( cnt[s[i]-'A']%4 == 3)
      {
        if (i+1==len) 
        {
          chk=1;
          printf("FAKE\n");
          break;
        }
        else if (s[i+1]==s[i])
        {
          cnt[s[i]-'A']++;
          i++;
        }
        else
        {
          chk=1;
          printf("FAKE\n");
          break;
        }
      }
    }

    if (!chk)
    {
      printf("OK\n");
    }
  }
}
