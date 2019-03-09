#include <stdio.h>
#include <string.h>

int main()
{
  int T;
  scanf("%d", &T);

  while(T--)
  {
    char s[(int)1e3+2];
    memset(s, 0, sizeof(s));
    scanf("%s", s);

    int len = strlen(s);
    int ans = len-1;

    int sum=0;
    for (int i=0; i<len; i++) sum += (s[i]-'0');

    while(sum >= 10)
    {
      ans += sum/10;
      sum = sum/10 + sum%10;
    }
    if (ans%2==0) printf("A\n");
    else printf("B\n");
  }

}
