#include <stdio.h>

char s[(int)1e5+1];
char dx['Z'], dy['Z'];
int main()
{
  int sx, sy, ex, ey;
  scanf("%d%d%d%d", &sx,&sy, &ex, &ey);
  int x_diff = ex-sx, y_diff = ey- sy;

  int n;
  scanf("%d", &n);
  scanf("%s", s);

  dx['U'] =0, dy['U'] =1;
  dx['D'] =0, dy['D'] =-1;
  dx['R'] =1, dy['R'] =0;
  dx['L'] =-1, dy['L'] =0;

  int cnt=0;
  for (int i=0; i<n; i++)
  {
    char c = s[i];
    int nx = dx[c], ny = dy[c];
    if ( ((long long )nx) *x_diff > 0) 
    {
      cnt++;
      if ( x_diff >0 ) x_diff--;
      else x_diff++;
    }
    else if ( ((long long)ny)*y_diff > 0) 
    {
      cnt++;
      if ( y_diff >0 ) y_diff--;
      else y_diff++;
    }
  }

  if (cnt==0) return !printf("-1\n");

  cnt*=2;
  x_diff = abs(x_diff);
  y_diff = abs(y_diff);

  long long days = ((x_diff+ y_diff+cnt-1)/(cnt))*((long long)n);





}
