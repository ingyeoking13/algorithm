#include <stdio.h>
#include <algorithm>

using namespace std;
int a[10][10];
char used[10][10];

int ans=1e9;

void go(int x, int y)
{
  if ( y == 10) 
  {
    go(x+1, 0);
    return;
  }

  if ( x== 10)
  {
    return;
  }

  if( used[x][y] )
  {
    go(x, y+1);
    return;
  }





}

int main()
{
  for (int i=0; i<10; i++)
  {
    for (int j=0; j<10; j++)
    {
      scanf("%d", &a[i][j]);
    }
  }

  for (int i=8; i>=0; i--)
  {
    for (int j=8; j>=0; j--)
    {
      if ( a[i][j] == 1 )
      {
        int mn = a[i-1][j];
        mn = min(a[i][j-1], mn);
        mn = min(a[i-1][j-1], mn);
        a[i][j] = mn +a[i][j];
      }
    }
  }

  go(0, 0);

}
