#include <stdio.h>

int dcol[4] = { 0, 1, 0, -1 };
int drow[4] = { 1, 0, -1, 0 };
int moving[2];

int main()
{
  int row, col;
  scanf("%d%d", &col, &row);
  int k;
  scanf("%d", &k);

  moving[0] = row;
  moving[1] = col;

  int x=0, y = 1;
  int dstate = 0;

  int state_cnt=0;
  int total_cnt=0;
  int ignore_moving = 0;

  while (k>0)
  {
    if (ignore_moving== moving[dstate%2])
    {
      return !printf("0\n");
    }

    for (int i=0; i<moving[dstate%2]-ignore_moving && k>0; i++)
    {
      x+=drow[dstate%4];
      y+=dcol[dstate%4];
      k--;
//      printf("%d %d\n", y, x);
    }

    if ( total_cnt == 0) ignore_moving++;
    else 
    {
      state_cnt++;
      if (state_cnt==2)
      {
        ignore_moving++;
        state_cnt=0;
      }
    }

    dstate++;
    total_cnt++;
  }
  printf("%d %d\n", y, x);
}
