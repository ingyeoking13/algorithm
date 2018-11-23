#include <stdio.h>
#include <vector>

using namespace std;
char s[4][5];
pair<int, int> al[15];

int diff(int a, int b) {
  int ret = a-b;
  return ret>0?ret:-ret;
}

int main()
{
  for (int i=0; i<4; i++)
  {
    scanf("%s", s[i]);
  }

  for (int i=0; i<4; i++)
  {
    for (int j=0; j<4; j++)
    {
      if (s[i][j] =='.') continue;
      al[s[i][j]-'A'] = {i, j};
    }
  }

  int ans=0;
  for (int i=0; i<15; i++)
  {
    ans += diff(al[i].first , i/4) + diff(al[i].second , i%4);
  }
  printf("%d\n", ans);

}
