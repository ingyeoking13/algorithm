#include <stdio.h>

char board[110][110];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        for (int j=x; j<x+10; j++)
        {
            for (int k=y; k<y+10; k++)
            {
                board[j][k]=1;
            }
        }
    }

    int ans=0;
    for (int i=0; i<110; i++)
    {
        for (int j=0; j<110; j++)
        {
            if (board[i][j]) ans++;
        }
    }
    printf("%d\n", ans);
}
