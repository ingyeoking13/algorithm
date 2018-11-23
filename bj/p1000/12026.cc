#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

char s[(int)1e3+1];
char arr[3] = { 'O', 'J', 'B' };
int val[1000];
int ret(char a) { if (a=='B') return 0; if (a=='O') return 1; return 2; }

int main()
{
  int n; scanf("%d", &n);
  scanf("%s", s);
  memset(val, 0x3f, sizeof(val));
  val[0]=0;

  for (int i=0;i<n; i++)
  {
    char now = s[i];
    for (int j=i+1; j<n; j++)
    {
      if (arr[ret(now)] == s[j])
      {
        val[j] = min(val[j], val[i]+ (j-i)*(j-i));
      }
    }
  }
  if (val[n-1] == 0x3f3f3f3f) printf("-1\n");
  else printf("%d\n", val[n-1]);
}
