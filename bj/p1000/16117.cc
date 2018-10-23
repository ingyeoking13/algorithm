#include <stdio.h>
#include <algorithm>
using namespace std;

long long d[1000][1000];
long long d2[1000][1000];
int a[1000][1000];
int main()
{
    int row, col;
    scanf("%d%d", &row, &col);

    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i=0; i<row; i++) d[i][0] =a[i][0];
    for (int i=0; i<row; i++) d2[i][0] =a[i][0];

    for (int j=1; j<col; j++)
    {
        for (int i=0; i<row; i++)
        {
            int nowcol = j;
            d[i][nowcol] = a[i][nowcol];

            for (int k=-1; k<=1; k++)
            {
                if (i+k <0 || i+k >= col) continue;
                if ( k==0 && nowcol-2 >=0)  d[i][nowcol] = max(d[i+k][nowcol-2] + a[i+k][nowcol-1]+a[i][nowcol], d[i][nowcol]);
                else d[i][nowcol] = max(d[i+k][nowcol-1]+a[i][nowcol], d[i][nowcol]);
            }

        }
    }
    for (int j=1; j<col+1; j++)
    {
        for (int i=0; i<row+1; i++)
        {
            int nowcol = j;
            d2[i][nowcol] =0;

            for (int k=-1; k<=1; k++)
            {
                if (i+k <0 || i+k >= col+1) continue;
                if ( k==0 && nowcol-2 >=0)  d2[i][nowcol] = d2[i][nowcol-2];
                else d2[i][nowcol] = max(d2[i+k][nowcol-1]+ a[i+k][nowcol-1], d[i][nowcol]);
            }

        }
    }


    long long ans=0;
    for (int i=0; i<row; i++)
    {
        //printf("%lld\n",d[i][col-1]);
        ans = max(d[i][col-1], ans);

    }
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++) printf("%lld  ",d[i][j]);
        printf("\n");
    }
    printf("%lld", ans);
}