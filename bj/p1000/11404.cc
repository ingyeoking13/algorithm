#include <stdio.h>
#include <string.h>

int d[101][101];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    memset(d, 0x3f, sizeof(d));

    while(m--)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        if ( d[u][v] > w) d[u][v]=w;
    }

    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            if (i==j) d[i][j]=0;

    for (int k=1; k<=n; k++)
    {
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=n; j++)
            {
                if (d[i][j] > d[i][k] + d[k][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            if (d[i][j]==0x3f3f3f3f) printf("-1 ");
            else printf("%d ", d[i][j]);
        }
        printf("\n");
    }
}