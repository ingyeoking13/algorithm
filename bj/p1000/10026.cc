#include <stdio.h>
#include <string.h>

char s[100][101];
char v[100][100];
int dx[4]={-1, 1, 0, 0}, dy[4] ={0, 0, -1, 1};

void go(int x, int y, int n, char state, char option)
{
    v[x][y]=1;
    if(s[x][y]=='G') s[x][y] = 'R';
    for (int i=0; i<4;i++)
    {
        int nx = x+dx[i], ny = y+dy[i];
        if (0<=nx &&  nx <n && 0<=ny && ny<n)
        {
            if (v[nx][ny]) continue;
            if (option == 0)
            {
                if (s[nx][ny] == state) go(nx, ny, n, state, option);
            }
            else 
            {
                if (s[nx][ny] == state)  go(nx, ny, n, state, option);
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%s", s[i]);
    
    for (int t=0; t<2; t++)
    {
        int ans=0;
        memset(v, 0, sizeof(v));

        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                //if (!v[i][j])
                {
                    ans++;
                    go(i,j, n, s[i][j], t);
                }
            }
        }
        printf("%d ", ans);
    }
    printf("\n");
}