#include <stdio.h>

long long ans=0;
long long before=0; // common sector while zizag
int ibveen=-1;
int board[2][(int)(3*1e5)];

long long zigzag_straight(int now, int len)
{
  long long ret=0;
  //zigzag
  ibveen=now;
  ret += before;

  int state=ibveen%2;
  int t=ibveen*2;
  for (int i=ibveen; i<=now; i++)
  {
    ret += ((long long)board[(0+state)%2][i])*t;
    t++;

    state++;
    ret += ((long long)board[(0+state)%2][i])*t;
    t++;
  }
  before = ret;

  for (int i=now+1; i<len; i++)
  {
    ret += ((long long)board[(0+state)%2][i])*t;
    t++;
  }

  state++;
  for (int i=len-1; i>now; i--)
  {
    ret += ((long long)board[(0+state)%2][i])*t;
    t++;
  }
  return ret;
}

int main()
{
  int max=0;
  int n; scanf("%d", &n);
  for (int i=0; i<n; i++) 
  {
    scanf("%d", &board[0][i]);
  }
  for (int i=0; i<n; i++) 
  {
    scanf("%d", &board[1][i]);
  }

  /*
  long long tmp=0;
  int t=0;

  for (int i=0; i<n; i++)
  {
    tmp += ((long long)t)*board[0][i];
    t++;
  }
  for (int i=n-1; i>=0; i--)
  {
    tmp += ((long long)t)*board[1][i];
    t++;
  }
  if (tmp> ans) ans= tmp;
  */

  //for (int i=0; i<n; i++)
  {
    tmp = zigzag_straight(i, n);
    if (tmp > ans) ans=tmp;
  }
  printf("%lld\n", ans);
}
