#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct Elem
{
  int arr[4][4];
  char col[4][4];
};

Elem elem[10];
bool used[10];
int series[3];
int n;
int ans=0;

int dx[4] = { 0, 0, 1, 1};
int dy[4] = { 0, 1, 0, 1};

void go(int cnt)
{
  if ( cnt == 3 )
  {
    int board[5][5];
    char col[5][5];
    memset(board, 0, sizeof(board));
    memset(col, 0, sizeof(col));

    for (int i=0; i<4; i++)
    {
      for (int j=0; j<4; j++)
      {
        for (int k=0; k<4; k++)
        {

          for (int q=0; q<3; q++)
          {
            for (int l=0; l<4; l++)
            {
              for (int m=0; m<4; m++)
              {
                if( q== 0) 
                {
                  board[dx[i]+l][dy[i]+m] += elem[ series[q] ].arr[l][m];
                  board[dx[i]+l][dy[i]+m] = max( board[dx[i]+l][dy[i]+m], 0);
                  board[dx[i]+l][dy[i]+m] = min( board[dx[i]+l][dy[i]+m], 9);

                  col[dx[i]+l][dy[i]+m] = elem[ series[q] ].col[l][m];
                }
                else if (q== 1)
                {
                  board[dx[j]+l][dy[j]+m] += elem[ series[q] ].arr[l][m];
                  board[dx[j]+l][dy[j]+m] = max( board[dx[j]+l][dy[j]+m], 0);
                  board[dx[j]+l][dy[j]+m] = min( board[dx[j]+l][dy[j]+m], 9);

                  col[dx[j]+l][dy[j]+m] = elem[ series[q] ].col[l][m];
                }
                else if ( q == 2)
                {
                  board[dx[k]+l][dy[k]+m] += elem[ series[q] ].arr[l][m];
                  board[dx[k]+l][dy[k]+m] = max( board[dx[k]+l][dy[k]+m], 0);
                  board[dx[k]+l][dy[k]+m] = min( board[dx[k]+l][dy[k]+m], 9);

                  col[dx[k]+l][dy[k]+m] = elem[ series[q] ].col[l][m];
                }
              }
            }
          }
        }
      }
    }

    int r=0, g=0, b=0, y=0;

    for (int i=0; i<5; i++)
    {
      for (int j=0; j<5; j++)
      {
        if ( col[i][j] == 'R' ) r+= board[i][j];
        else if ( col[i][j] == 'G' ) g+= board[i][j];
        else if ( col[i][j] == 'B' ) b+= board[i][j];
        else if ( col[i][j] == 'Y' ) y+= board[i][j];
      }
    }

    int tmp = 7*r + 5*b + 3*g + 2*y;
    if (tmp > ans ) ans =tmp;

    return;
  }

  for (int i=0; i<n; i++)
  {
    if ( used[i] ) continue;
    used[i] = 1;
    series[cnt] = i;
    go( cnt+1 );
    used[i] = 0;
  }
}

int main()
{
  scanf("%d", &n);

  for (int k=0; k<n; k++)
  {

    for (int i=0; i<4; i++)
    {
      for (int j=0; j<4; j++)
      {
        int tmp;
        scanf("%d", &tmp);
        elem[k].arr[i][j] = tmp;
      }
    }

    for (int i=0; i<4; i++)
    {
      for (int j=0; j<4; j++)
      {
        char tmp[3];
        scanf("%s", tmp);
        elem[k].col[i][j] = tmp[0];
      }
    }
  }

  go(0);
  printf("%d\n", ans);


}
