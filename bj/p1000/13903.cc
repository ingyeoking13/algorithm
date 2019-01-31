#include <stdio.h>
#include <string.h>
#include <queue> // 상태 저장을 위해 queue 를 하자.각 상태간 이동 비용이 동일하게끔..

using namespace std;

struct Rule
{
  int dx, dy;
  Rule(int xx, int yy) { dx=xx; dy= yy;}
};

struct Pos
{
  int x, y;
  Pos(int xx, int yy) { x=xx; y= yy;}
  Pos& operator+(const Rule& r)
  {
    x = x+r.dx;
    y =y+r.dy;
  }
  void add(const Rule& r)
  {
    x = x + r.dx;
    y = y+r.dy;
  }
};

int m[(int)1e3+1][(int)1e3+1];
int d[(int)1e3+1][(int)1e3+1];
int main()
{
  int row, col;
  scanf("%d%d", &row, &col);
  for (int i=0; i<row; i++)
  {
    for (int j=0; j<col; j++)
    {
      scanf("%d", &m[i][j]);
    }
  }

  memset(d, -1, sizeof(d));
  queue<Pos> q;
  for (int i=0; i<col; i++)
  {
    if ( m[0][i] == 1 ) 
    {
      q.push(Pos(0, i));
      d[0][i] = 0;
    }
  }


  // 규칙 셋 받기
  int n; scanf("%d", &n);
  vector<Rule> rules;

  while(n--)
  {
    int dx, dy;
    scanf("%d%d", &dx, &dy);
    rules.push_back(Rule(dx, dy));
  }

  while(!q.empty()) // 자 이제 그럼 탐색을 시작해보자. 
  {
    auto now = q.front();
    q.pop();

    for (int i=0; i<rules.size(); i++)
    {
      auto temp = now;
      temp = temp + rules[i];
//      temp.add(rules[i]);
      if ( temp.x < 0 || temp.x >= row || temp.y <0 || temp.y >= col ) continue;
      if ( d[temp.x][temp.y] >=0 || m[temp.x][temp.y] == 0 ) continue;
      d[temp.x][temp.y] = d[now.x][now.y] +1;
      q.push(Pos(temp.x, temp.y));
    }
  }

  int ans= 1e9;
  for (int i=0; i<col; i++)
  {
    if ( ans > d[row-1][i] && d[row-1][i]!=-1 ) ans = d[row-1][i];
  }

  if (ans == 1e9) printf("-1\n");
  else printf("%d\n", ans);
}
