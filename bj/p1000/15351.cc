#include <stdio.h>
#include <string.h>

int main()
{
  char in[33];
  int T;
  scanf("%d\n", &T);
  while(T--)
  {
    int ans=0;
    fgets(in, 33, stdin);
    int len = strlen(in);

    for (int i=0; i<len; i++)
    {
      if (in[i] == ' ') continue;
      if (in[i] == '\n') continue;
      ans = ans + (in[i]-'A'+1);
    }
    if (ans == 100) printf("PERFECT LIFE\n");
    else printf("%d\n", ans);
  }
}
