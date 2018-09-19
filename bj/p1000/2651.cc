#include <stdio.h>

int dist[100], cost[100];
pair<int, int> state[101];

int go(int now, int n, int move)
{

  if ( state[now].first

}

int main()
{
  int n, move;
  scanf("%d %d", &move, &n);

  for (int i=0; i<n ;i++) scanf("%d", &dist[i]);
  for (int i=0; i<n ;i++) scanf("%d", &cost[i]);

  state[0]= {0, dist};

  dfs(0, n, move);

}
