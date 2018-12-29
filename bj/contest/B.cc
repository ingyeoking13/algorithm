#include <stdio.h>
#include <string>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int retf(char* str)
{
  int ret = 0;
  if (str[0] == 'M' || str[1] == 'M') ret|=2;
  if (str[1] == 'F' || str[0] == 'F') ret|=1;
  return ret;
}

int main()
{
  char name[(int)1e1+1], g[3];
  int dist;
  scanf("%s", name);
  scanf("%s", g);
  scanf("%d", &dist);
  int m;
  scanf("%d", &m);

  int gg = retf(g);
  gg = 3^gg;
  bool chk=0;

  vector<string> ans;

  while(m--)
  {
    char tmpname[(int)1e2+1];
    int dd;
    scanf("%s %s %d", tmpname, g, &dd);
    int ggg = retf(g);

    if ( gg^ggg ) 
    {
      if ( dist >= dd)
      {
        chk=1;
        ans.push_back(tmpname);
      }
    }
  }

  if (!chk)
  {
    printf("No one yet\n");
  }
  else
  {
    sort(ans.begin(), ans.end());
    for (int i=0; i<ans.size(); i++)
    {
      printf("%s\n", ans[i].c_str());
    }
  }
}
