#include <stdio.h>
#include <queue>

using namespace std;

char s[1000][1000];
char v[1000][1000];
int Q_dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0};
int Q_dy[8] = { -1, 0, 1, -1, 0, 1, -1, 1};

int K_dx[8] = { 2, 2, -2, -2, 1, 1, -1, -1};
int K_dy[8] = { 1, -1, 1, -1, 2, -2, 2, -2};

int main()
{
  int row, col;
  scanf("%d %d",  &row, &col);

  for (int i=0; i<3; i++)
  {
    int n;
    scanf("%d", &n);
    while(n--)
    {
      int x, y;
      scanf("%d %d", &x, &y);
      if(i==0) s[x-1][y-1] = 'Q';
      else if ( i==1) s[x-1][y-1] = 'K';
      else s[x-1][y-1] = 'P';
      v[x-1][y-1]=1;
    }
  }

  queue<pair<int, int>> Qq;
  queue<pair<int, int>> Kq;
  for (int i=0; i<row; i++)
  {
    for (int j=0; j<col; j++)
    {
      if (s[i][j] == 'K') Kq.push({i, j});
      else if (s[i][j] == 'Q') {
        Qq.push({i, j});
     //   printf("%d %d QUEEN PUSHED\n", i, j);
      }
    }
  }

  while(!Qq.empty())
  {
    pair<int, int> now = Qq.front();
    Qq.pop();
    int x = now.first, y= now.second;
    //printf("%d %d QUEEN\n", x, y);
    for (int i=0; i<8; i++)
    {
      int nx = x+Q_dx[i],ny= y+Q_dy[i];
    //  printf("%d %d Q MOVE\n", nx, ny);
      while(1)
      {
        if (0<=nx && 0<=ny && nx <row && ny<col && s[nx][ny]==0)
        {
          v[nx][ny]=1;
        }
        else break;

        nx +=Q_dx[i], ny+=Q_dy[i];
      }
    }

  }

  while(!Kq.empty())
  {
    pair<int, int> now= Kq.front();
    Kq.pop();
    int x = now.first, y= now.second;
   // printf("%d %d HORSE\n", x, y);
    for (int i=0; i<8; i++)
    {
      int nx = x+K_dx[i],ny= y+K_dy[i];
//    printf("%d %d H MOVE\n", nx, ny);
      if (0<=nx && 0<=ny && nx <row && ny<col && s[nx][ny]==0) v[nx][ny]=1;
    }
  }

  int ans=0;
  for (int i=0; i<row; i++)
  {
    for (int j=0; j<col; j++)
    {
      if (!v[i][j]) ans++;
 //     printf("%d",v[i][j]);
    }
  //  printf("\n");
  }
  printf("%d\n", ans);

}
