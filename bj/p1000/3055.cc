#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;

queue<pair<int, int>> q;
vector<pair<int, int>> vec;
char d[50][50];
int v[50][50], v2[50][50];

int dx[4]= {-1, 1, 0, 0};
int dy[4]= {0, 0, -1, 1};

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);

  pair<int, int> w, s, e;
  for (int i=0; i<n; i++)
  {
    scanf("%s", d[i]);
    for (int j=0; j<m; j++)
    {
      if (d[i][j] == 'S') s.first = i, s.second=j;
      else if (d[i][j] == 'D') e.first = i, e.second=j;
      else if (d[i][j] == '*') vec.push_back({i, j});
    }
  }

  v[s.first][s.second]=1;
  memset(v2, 0x3f, sizeof(v2));

  for (int j=0; j<2; j++)
  {
    if (j==1) q.push(s);
    else if (j==0) 
    {
      for (int i=0; i<vec.size(); i++)
      {
        q.push(vec[i]);
        v2[vec[i].first][vec[i].second]=1;
      }
    }

    while(!q.empty())
    {
      pair<int, int> now = q.front();
      q.pop();

      int x = now.first, y = now.second;
      for (int i=0; i<4; i++)
      {
        int nx = x+dx[i], ny = y+dy[i];
        if (!(0<= nx && 0<= ny && nx<n && ny <m)) continue;
        if (j ==1)
        {
          if (!v[nx][ny] && d[nx][ny]!='X' )
          {
            if ( v[x][y]+1 <v2[nx][ny] || v2[nx][ny]==0 )
            {
              v[nx][ny]=v[x][y]+1;
              q.push({nx, ny});
            }
          }
        }
        else 
        {
          if (v2[nx][ny] > v2[x][y]+1 && d[nx][ny]!='X' && d[nx][ny] != 'D' )
          {
            v2[nx][ny] = v2[x][y]+1;
            q.push({nx,ny});
          }
        }
      }
    }
  }

  int ans = v[e.first][e.second]-1;
  if (ans == -1 ) printf("KAKTUS\n");
  else printf("%d\n",ans);
}
