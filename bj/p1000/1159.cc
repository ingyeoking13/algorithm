#include <stdio.h>

int cnt[26];

int main()
{
  int n;scanf("%d", &n);
  char s[31];
  while(n--)
  {
    scanf("%s", s);
    cnt[s[0]-'a']++;
  }

  int chk=0;
  for (int i=0; i<26; i++)
  {
    if (cnt[i] >=5 )
    {
      chk=1;
      printf("%c", 'a'+i);
    }
  }

  if (chk==0)
  {
    printf("PREDAJA");
  }
  printf("\n");

}
