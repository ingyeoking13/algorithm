#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <vector>

using namespace std;

char s[(int)1e4][500];
char vis[(int)1e4][500];
int dx[8] ={ -1, -1, -1, 1, 1, 1, 0, 0};
int dy[8] ={ -1, 0, 1, -1, 0, 1, 1, -1};

struct vertex
{
  int x; int y; 
  vertex(int x, int y) : x(x), y(y) {}
  vertex() : x(0), y(0) {};
};
vector<vector<vertex>> pre;
vector<vector<vector<vertex>>> edge;
vector<vertex> start;

int dfs(int x, int y, int dest)
{
  if (vis[x][y]) return 0;
//  printf("%d %d to ->>>\n", x, y);
  vis[x][y]=1;
  if (y == dest)
  {
    return 1;
  }
  for (int i=0; i<edge[x][y].size(); i++)
  {
    int nx = edge[x][y][i].x, ny = edge[x][y][i].y; 
    if (vis[nx][ny] ) continue;
    if (ny == 0) continue;

    if ( pre[nx][ny].x == -1)
    {
      if (dfs(nx, ny, dest))
      {
        pre[nx][ny] = {x, y};
        return 1;
      }
    }
    else if (pre[nx][ny].x != -1)
    {
      if (dfs(pre[nx][ny].x, pre[nx][ny].y, dest))
      {
        pre[nx][ny] = {x, y};
        return 1;
      }
    }
  }
  return 0;

}

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i=0; i<n; i++)
  {
    scanf("%s", s[i]);
  }

  edge.resize(n);
  pre.resize(n);
  for (int i=0; i<n; i++) 
  {
    edge[i].resize(m);
    pre[i].resize(m);
  }

  for (int i=0; i<n; i++)
  {
    for (int j=0; j<m; j++)
    {
      pre[i][j] = {-1, -1};

    }
  }

  for (int i=1; i<n; i++)
  {
    for (int j=0; j<m; j++)
    {
      for (int k=0; k<8; k++)
      {
        int x= i, y= j;

        int nx = x+dx[k], ny = y+dy[k];
        if (0<= nx && 0 <= ny && nx<n && ny<m )
        {
          if (s[nx][ny] == '.') edge[x][y].push_back({nx, ny});
        }
      }
    }
  }

  for (int i=0; i<n; i++)
  {
    if (s[i][0] == '.' ) 
    {
      start.push_back({i,0});

      if (i+1 <n) edge[i][0].push_back({i+1, 1});
      if (i-1 >=0) edge[i][0].push_back({i-1, 1});
      edge[i][0].push_back({i, 1});
    }
  }

  int ans=0;
  for (int i=0; i<start.size(); i++)
  {
    memset(vis, 0, sizeof(vis));
    if (dfs(start[i].x, start[i].y, m-1))
    {
      ans++;
    }
  }
  printf("%d\n", ans);

}
