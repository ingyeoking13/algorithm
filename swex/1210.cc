#include <stdio.h>

int a[100][100], b[100];
void go ( int x, int y, int step, int col )
{
  a[x][y] = col;
  if ( x == 99 ) 
  {
    a[x][y] = step;
    b[y] = col-2;
    return;
  }

  if ( y-1 >= 0 && a[x][y-1] !=0 && a[x][y-1] != col )
  {
    go (x, y-1, step+1, col);
  }
  else if ( y+1 < 100 && a[x][y+1] != 0 && a[x][y+1] != col )
  {
    go(x, y+1, step+1, col);
  }
  else if ( x+1 < 100 && a[x+1][y] != 0 && a[x+1][y] != col)
  {
    go(x+1, y, step+1, col);
  }
}

int main()
{
  for (int test_case=1; test_case<=10; test_case++)
  {
    int T;
    scanf("%d", &T);

    int sx, sy;
    for (int i=0; i<100; i++)
    {
      for (int j=0; j<100; j++)
      {
        scanf("%d", &a[i][j]);
      }
    }

    for (int i=0; i<100; i++)
    {
      if ( a[0][i] ==1 )
      {
        go ( 0, i, 0, i+2 );
      }
    }

    int mn = 1e9, ans=-1;
    for (int i=0; i<100; i++)
    {
      if ( a[99][i] > 0)
      {
        if ( mn > a[99][i] )
        {
          mn = a[99][i];
          ans = b[i];
        }
      }
    }

    printf("#%d %d\n", test_case, ans);
  }
}
