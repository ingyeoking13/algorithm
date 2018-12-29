#include <stdio.h>
#include <string.h>

int e[(int)1e3][(int)1e3];
int min(int a, int b) { return a>b?b:a; }

int main()
{
  int n, m;
  scanf("%d%d",&n, &m);
  memset(e, 0x7f, sizeof(e));

  while(m--)
  {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    u--, v--;
    e[u][v] = min(e[u][v], w);
  }

  int u, v; 
  scanf("%d%d", &u, &v);

  u--, v--;
  int Queue[(int)1e3];
  int h = 0, t=0;
  int d[(int)1e3]; 
  char vis[(int)1e3];

  memset(d, 0x7f, sizeof(d));
  memset(vis, 0, sizeof(vis));

  Queue[t++] = u;
  d[u] = 0;

  while(h<t)
  {
    int now = Queue[h++];
    vis[now] = 1;

    for (int i=0; i<n; i++)
    {
      if (vis[i]) continue;
      if (e[now][i] == 0x7f7f7f7f) continue; // no edge

      if ( d[i] > d[now] + e[now][i])
      {
        d[i] = d[now] + e[now][i];
      }
    }

    int next=-1, mn = 0x7f7f7f7f;

    for (int i=0; i<n; i++)
    {
      if (vis[i]) continue;
      if (mn > d[i] ) 
      {
        mn = d[i]; 
        next = i;
      }
    }

    if (next>=0) Queue[t++]=next;

  }

  printf("%d\n", d[v]);

}
