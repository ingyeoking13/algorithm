#include <stdio.h>
#include <string.h>
#include <vector>

//char e[(int)1e3+1][(int)1e3+1];
using namespace std;
vector<int> e[(int)1e3+1];
char visit[(int)1e3+1][(int)1e3+1];
int p[(int)1e3+1];
int a, b;

bool matched(int now)
{
  for (int j=0; j<e[now].size(); j++)
  {
    int i = e[now][j];

    if ( visit[now][i]) continue;
    visit[now][i] =1;

    if ( p[i] == 0 )
    {
      p[ i ] = now;
      return true;
    }
    else
    {
      if ( matched( p[i] ))
      {
        p[ i ] = now;
        return true;
      }
    }
  }

  return false;
}

int main()
{

  scanf("%d%d", &a, &b);
  for (int i=1; i<=a; i++)
  {
    int m;
    scanf("%d", &m);

    while(m--)
    {
      int u;
      scanf("%d", &u);
      e[i].push_back(u);
    }
  }

  int ans=0;
  for (int i=1; i<=a; i++)
  {
    memset(visit, 0, sizeof(visit));
    if (  matched(i) ) ans++;
  }
  printf("%d\n", ans);

}
