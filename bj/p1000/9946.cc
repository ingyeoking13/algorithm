#include <stdio.h>
#include <string.h>

int main()
{
  char s[(int)1e3+1];
  int test_case =1;
  while(scanf("%s", s))
  {
    if (strcmp(s, "END")==0) return 0;

    char s2[(int)1e3+2];
    scanf("%s", s2);


    int len = strlen(s);
    int len2 = strlen(s2);

    if ( len != len2) 
    {
      printf("Case %d: different\n", test_case++);
      continue;
    }

    int cnt[26];
    memset(cnt, 0, sizeof(cnt));

    for (int i=0; i<len; i++) cnt[s[i]-'a']++;
    for (int i=0; i<len; i++) cnt[s2[i]-'a']--;
    bool chk=true;
    for (int i=0; i<26; i++) 
    {
      if ( cnt[i] != 0) chk=false;
    }

    if (chk) printf("Case %d: same\n", test_case++);
    else printf("Case %d: different\n", test_case++);
  }
}
