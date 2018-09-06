#include <stdio.h>
#include <string.h>

char s[5][6];
int v[5][5];
int dx[4] ={-1, 1, 0, 0};
int dy[4] ={0, 0, -1, 1};
char map[1<<25];
int ans=0;

void go(int now, char* a)
{
  int tmp=0;
  for (int i=0; i<=now; i++)
  {
    tmp |= (1<<a[i]);
  }
  if (map[tmp]) return;

  map[tmp]=1;

  if (now == 6)
  {
    long long tmp=0;
    for (int i=0; i<7; i++)
    {
      if (s[a[i]/5][a[i]%5]=='S') tmp++;
      else tmp--;
    }
    if (tmp<=0) return;

    tmp=0;
    for (int i=0; i<7; i++)
    {
      tmp |= (1<<a[i]);
    }

    if(chk.find(tmp) == chk.end())
    {
      chk[tmp]=1;
      ans++;
    }
    return;
  }

  for (int i=0; i<=now; i++)
  {
    int x = a[i]/5, y = a[i]%5;

    for (int j=0; j<4; j++)
    {
      int nx = x+dx[j], ny= y+dy[j];
      if (nx<0 || ny<0 || nx>=5 || ny>=5) continue;
      if (v[nx][ny]) continue;

      v[nx][ny]=1;
      a[now+1]=nx*5+ny;
      go(now+1, a);
      v[nx][ny]=0;
    }
  }

}

int main()
{
  for (int i=0; i<5; i++)
  {
    scanf("%s", s[i]);
  }

  for (int i=0; i<5; i++)
  {
    for (int j=0; j<5; j++)
    {
      char a[7];

      memset(v,0, sizeof(v));
      v[i][j]=1;

      a[0]=i*5+j;
      go(0, a);
    }
  }

  printf("%d\n", ans);
}
