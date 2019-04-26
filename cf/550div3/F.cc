#include <stdio.h>
#include <vector>
using namespace std;

int col[(int)2e5+1];
bool visit[(int)2e5+1];
bool chk=true;
vector<int> e[(int)2e5+1];
int input[(int)2e5];

void go(int now, int mycol)
{
  visit[now] =true;

  for (int i=0; i<e[now].size(); i++)
  {

    int next = e[now][i];

    if ( visit[next] )
    {
      if ( mycol  == col[next] ) chk=false;
    }
    else
    {
      col[next] = 3-mycol;
      go(next, col[next] );
    }
  }
}

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i=0; i<m; i++)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    input[i] = u;
    e[u].push_back(v);
    e[v].push_back(u);
  }

  col[1] = 1;
  go(1,col[1]);

  if( !chk) return !printf("NO\n");

  printf("YES\n");
  for (int i=0; i<m; i++)
  {
    if ( col[ input[i] ] == 1 ) printf("1");
    else printf("0");
  }
  printf("\n");

}
