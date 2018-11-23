#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

char a[20][21];
int dx[4] ={-1, 1, 0, 0};
int dy[4] ={0, 0, -1, 1};

int main()
{
  int row, col; scanf("%d%d", &row, &col);

  int cities=0;
  for (int i=0; i<row; i++)
  {
    scanf("%s", a[i]);
    for (int j=0; j<col; j++)
    {
      if (a[i][j]=='1') cities++;
    }
  }
  //printf("%d\n", cities);
  int ans= (int)1e9;

  for (int i=0; i<row; i++)
  {
    for (int j=0; j<col; j++)
    {

      for (int k=i; k<row; k++)
      {
        for (int l=j+1; l<col; l++)
        {

          if (a[i][j] == '1' || a[k][l] == '1' ) continue;

          int x = i, y = j;
          int x2 = k, y2 = l;
          bool vis[20][20];
          int d[20][20];
          memset(vis, 0, sizeof(vis));
          memset(d, 0, sizeof(d));

          queue<pair<int, int>> q;

          q.push({x, y});
          q.push({x2, y2});
          vis[x][y]=1, vis[x2][y2] =1;
          int temp=0;

          while(!q.empty())
          {
            pair<int, int> now = q.front();
            q.pop();
            int x= now.first, y = now.second;

            for (int i=0; i<4; i++)
            {
              int nx = x+dx[i], ny = y+dy[i];
              if (0>  nx || nx >=row || ny <0  || ny >= col) continue;

              if (vis[nx][ny]) continue;

              vis[nx][ny]=1;
              d[nx][ny] = d[x][y]+1;
              q.push({nx,ny});

              if (a[nx][ny] =='1') 
              {
                temp++;
              }
            }
            if (temp == cities) 
            {
//              printf("tmp cities %d %d\n", temp, cities);
              break;
            }
          }

          int mx=0;
          for (int m=0; m<row; m++)
          {
            for (int n=0;n<col; n++)
            {
              if (mx<d[m][n]) mx=d[m][n];
            }
          }

          if (mx < ans) {
            ans =mx;
 //           printf("%d %d\n%d %d\n", x, y, x2, y2);
          }
        }
      }
    }
  }

  printf("%d\n", ans);
}
