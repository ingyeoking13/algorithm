#include <stdio.h>

int presum[1001][1001];
int main()
{
  int row, col, Q;
  scanf("%d%d%d", &row, &col, &Q);

  for (int i=1; i<=row; i++)
  {
    for (int j=1; j<=col; j++)
    {
      int tmp;
      scanf("%d", &tmp);
      presum[i][j] = presum[i][j-1] + tmp;
    }
  }

  while(Q--)
  {
    int fx, fy, tx, ty;
    scanf("%d%d%d%d",&fx, &fy, &tx, &ty);

    long long ans =0;
    for (int i=fx; i<=tx; i++)
    {
      ans = ans + presum[i][ty] - presum[i][fy-1];
    }
    printf("%lld\n", ans/ ((ty-fy+1)*(tx-fx+1)) );
  }

}
