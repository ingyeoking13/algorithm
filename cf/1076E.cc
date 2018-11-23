#include <stdio.h>
#include <vector>

int n;
vector<int> e[(int)3e5];
int main()
{

  scanf("%d", &n);
  for (int i=0; i<n-1; i++)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  int m;
  scanf("%d", &m);
  while(m--)
  {
    int x, d, val;
    scanf("%d%d%d", &x, &d, &val);
    x--;
    q[x].push_back(
  }


}
