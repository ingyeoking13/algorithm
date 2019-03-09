#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;
char map[2002][2002];
int dx[4] ={-1, 1,0, 0}, dy[4]= {0, 0, -1, 1};
int main()
{
  int T;
  scanf("%d", &T);

  while(T--)
  {
    memset(map, 0, sizeof(map));
    int x= 1000, y =1000;

    int query;
    scanf("%d", &query);

    while(query--)
    {
      char oper[3];
      int scale;
      scanf("%s%d", oper, &scale);
      int dirx, diry;

      if ( oper[0] == 'x' ) { dirx=1, diry=0; }
      else if ( oper[0] == 'y' ) { dirx=1, diry=1; }
      else { dirx=0, diry=1; }

      if (scale<0)
      {
        diry *=-1;
        dirx *=-1;
        scale=-scale;
      }
      for (int i=1; i<=scale; i++)
      {
        map[x+dirx*i][y+diry*i]=1;
      }
      x = x+dirx*scale, y = y+diry*scale;
    }
    queue<pair<int, int> > q;

    map[2001][2001] = 2;
    q.push(make_pair(2001, 2001));

    while(!q.empty())
    {
      pair<int, int> pos = q.front();
      q.pop();
      int posx= pos.first;
      int posy= pos.second;
      for (int i=0; i<4; i++)
      {
        int nx = posx +dx[i], ny = posy+dy[i];
        if ( nx <0 || nx>=2002 || ny<0 || ny>= 2002 ) continue;
        if ( map[nx][ny] != 0) continue;
        map[nx][ny]=2;
        q.push(make_pair(nx,ny));
      }
    }

    x=-1, y=-1;
    for (int i=0; i<=2000; i++)
    {
      for (int j=0; j<=2000; j++)
      {
        if ( map[i][j] == 0) 
        {
          x=i, y=j;
          break;
        }
      }
      if ( x!=-1 ) break;
    }

    if ( x!= -1 ) 
    {
      map[x][y] = 1;
      q.push(make_pair(x, y));

      while(!q.empty())
      {
        pair<int, int> pos = q.front();
        q.pop();
        int posx= pos.first;
        int posy= pos.second;
        for (int i=0; i<4; i++)
        {
          int nx = posx +dx[i], ny = posy+dy[i];
          if ( nx <0 || nx>=2002 || ny<0 || ny>= 2002 ) continue;
          if ( map[nx][ny] != 0) continue;
          map[nx][ny]=1;
          q.push(make_pair(nx,ny));
        }
      }
    }

    int ans=0;
    for (int i=0; i<=1999; i++)
    {
      for (int j=0; j<=1999; j++)
      {
        int x = i, y = j;
        int cnt = 0;
        for (int k=0; k<2; k++)  
        {
          for (int l=0; l<2; l++)
          {
            if ( map[x+k][y+l]==1 ) cnt++;
          }
        }
        if (cnt ==3 ) ans += 1;
        else if ( cnt == 4) ans +=2;
      }
    }
    printf("%d\n", ans);
  }
}
