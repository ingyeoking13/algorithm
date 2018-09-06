#include <stdio.h>

char board[10][11];

int dx[4] ={-1, 1, 0, 0};
int dy[4] ={0, 0, -1, 1};

int main()
{
  int row, col; 
  scanf("%d %d", &row, &col);

  for (int i=0; i<row; i++)
  {
    scanf("%s", board[i]);
  }

  int ans=1;
  for (int i=0; i<row; i++)
  {
    for (int j=0; j<col; j++)
    {
      if (board[i][j] == '.')
      {
        int cnt =0;
        for (int k=0; k<4; k++)
        {
          int nx = i+dx[k], ny = j+dy[k];

          if (nx >=0 && ny >=0  && nx < row && ny <col )
          {
            if (board[nx][ny]=='.') cnt++;
          }
        }
        if (cnt<2)
        {
          return !printf("1\n");
        }
      }
    }
  }
  printf("0\n");

}
