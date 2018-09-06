#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
char s[11];
int main()
{
  scanf("%s", s);
  int len = strlen(s);
  sort(s, s+len);
  int ans=0;

  do
  {
    int chk=1;
    for (int i=0; i<len-1; i++)
    {
      if (s[i] == s[i+1])
      {
        chk=0;
        break;
      }
    }
    if (chk) ans++;

  }while(next_permutation(s, s+len));

  printf("%d\n", ans);

}
