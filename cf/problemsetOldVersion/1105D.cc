#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct pos
{
  int x, y, mv;
  pos(int x, int y, int mv) : x(x), y(y) , mv(mv) {};
};
int dx[4] ={-1, 1, 0, 0};
int dy[4] ={0, 0, -1, 1};

vector<pair<int, int> > v;
bool visit[(int)1e3][(int)1e3];
char s[(int)1e3][(int)1e3+5];
queue<pos> q[10];

int anscnt[10];

int main()
{
  int row, col, p;
  scanf("%d%d%d", &row, &col, &p);

  for (int i=0; i<p; i++)
  {
    int speed;
    scanf("%d", &speed);
    v.push_back(make_pair(speed, i+1));
  }

  sort(v.begin(), v.end());
  for (int i=0; i<row; i++)
  {
    scanf("%s", s[i]);
    for (int j=0; j<col; j++)
    {
      if ( s[i][j] != '.'  && s[i][j] != '#') 
      {
        q[s[i][j]-'0'].push(pos(i, j, 0));
        visit[i][j] = true;
      }
    }
  }

  while(true)
  {
    bool updated = false;
    for (int i=0; i<p; i++)
    {
      int speed = v[i].first;
      int num = v[i].second;

      while(!q[num].empty())
      {
        auto now = q[num].front();
        if (now.mv  == speed) break;
        q[num].pop();

        for (int i=0; i<4; i++)
        {
          int nx = dx[i]+now.x, ny = dy[i]+now.y;

          if ( nx <0 || nx >= row ||  ny <0 || ny >= col ) continue;
          if ( visit[nx][ny] ) continue;
          if ( s[nx][ny]=='#' ) continue;

          visit[nx][ny] =true;
          s[nx][ny]='0'+num;
          q[num].push(pos(nx, ny, now.mv+1));
          updated=true;

        }
      }
      queue<pos> tmp;
      while (!q[num].empty())
      {
        auto cur = q[num].front();
        tmp.push(pos(cur.x, cur.y, 0));
        q[num].pop();
      }

      while (!tmp.empty())
      {
        q[num].push(tmp.front());
        tmp.pop();
      }
    }

    if (!updated) break;
  }

  for (int i=0; i<row; i++)
  {
    for (int j=0; j<col; j++)
    {
      int num = s[i][j]-'0';
      if (num >= 0 && num <=9)
      {
        anscnt[ num ]++;
      }
    }
  }

  for (int i=1; i<=p; i++)
  {
    printf("%d ", anscnt[i]);
  }
  printf("\n");

}
