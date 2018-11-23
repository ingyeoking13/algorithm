#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char s[(int)1e6+1];
int arr[2];

bool ret(char a) { return a=='1'; }

int main()
{
  scanf("%s", s);
  int len = strlen(s);

  bool st= (s[0]=='1');
  for (int i=1; i<len; i++)
  {
    if (st != ret(s[i])) 
    {
      arr[st]++;
      st= ret(s[i]);
    }
  }
  arr[st]++;

  printf("%d\n", min(arr[0], arr[1]));
}
