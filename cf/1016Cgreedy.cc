#include <stdio.h>

int board[2][(int)(3*1e5)];
int main()
{
  int n; scanf("%d", &n);

  for (int i=0; i<n; i++) 
  {
    scanf("%d", &board[0][i]);
  }
  for (int i=0; i<n; i++) scanf("%d", &board[1][i]);

}
