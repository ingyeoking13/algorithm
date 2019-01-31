#include <stdio.h>

char s[(int)2e5+5];
int anscnt[26];
int curcnt[26];
int main()
{
  int n, k;
  scanf("%d%d", &n, &k);

  scanf("%s",s);

  curcnt[s[0]-'a']++;
  if (curcnt[s[0]-'a']==k) curcnt[s[0]-'a']=0, anscnt[s[0]-'a']++;

  int prev = s[0]-'a';

  for (int i=1; i<n; i++)
  {
    int now = s[i]-'a';
    curcnt[now]++;

    if (curcnt[now] == k) anscnt[now]++, curcnt[now]=0;
    if (prev !=  now) curcnt[prev]=0;
    prev = now;
  }

  int ans=0;
  for (int i=0; i<26; i++)
  {
    if (ans < anscnt[i] ) ans=anscnt[i];
  }
  printf("%d\n", ans);
}
