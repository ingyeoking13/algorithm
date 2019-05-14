#include <iostream>

using namespace std;
char s[(int)1e2][(int)1e2+3];
bool v[(int)1e2][(int)1e2];
int yy[(int)1e2];

int dx[4] = {-1, 1, 0, 0}; 
int dy[4] = { 0, 0, -1, 1};

void go(int x, int y)
{
  for (int i=0; i<4; i++)
  {
    int nx = x+dx[i], ny = y+dy[i];
    if ( nx < 0 || nx >= row || y <0 || ny >= col ) continue;
    if ( s[nx][ny] == '.' ) continue;
    if ( v[nx][ny] ) continue;

    go(nx, ny);
  }

}

int main()
{
  int row , col;
  cin >> row >> col;

  for (int i=0; i<row; i++)
  {
    cin >> s[i];
  }

  int q;
  for (int i=0; i<q; i++)
  {
    int h;
    cin >> h;

    int y = (i%2==0)?0:col-1;
    int dy = (i%2==0)?1:-1;

    while ( y< col && y >=0 && s[h][y] =='.') y+=dy;
    if ( y >= col  ||  y< 0 ) continue;

    s[h][y] = '.';

    int x = h;

    memset(v, 0, sizeof(v));
    for (int i=0; i<4; i++)
    {
      memset(yy, -1, sizeof(yy));

      int nx = x+dx[i], ny = y+dy[i];
      if ( nx < 0 || nx >= row || y <0 || ny >= col ) continue;
      if ( s[nx][ny] == '.' ) continue;
      if ( v[nx][ny] ) continue;

      v[nx][ny] =true;

      go(nx, ny);




    }

  }

}
