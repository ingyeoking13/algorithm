#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;
char s[1000][1001];
char v[1000][1000][11];
int dist[1000][1000][11];
int dx[4] ={-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

struct state
{
    int x, y, k, d;
    state(int x, int y, int k, int d) : x(x), y(y), k(k), d(d){}
};
int main()
{
    int row, col, mxk; scanf("%d%d%d", &row, &col, &mxk);
    for (int i=0; i<row; i++) scanf("%s",s[i]);
    memset(dist, -1, sizeof(dist));

    queue<state> q;

    dist[0][0][0]=0;
    v[0][0][0]=1;
    q.push({0,0,0,0});
    while(!q.empty())
    {
        auto now = q.front();
        q.pop();
        int x= now.x, y = now.y, k= now.k, d = now.d;
        for (int i=0; i<4; i++)
        {
            int nx = x+dx[i], ny = y+dy[i];
            if ( nx <0 || ny <0 || nx>=row || ny >=col) continue;

            if (s[nx][ny] == '1'  && k < mxk && !v[nx][ny][k+1])
            {
                dist[nx][ny][k+1] = d+1;
                v[nx][ny][k+1] = 1;
                q.push({nx,ny,k+1,d+1});
            }
            else if (s[nx][ny]== '0' && !v[nx][ny][k])
            {
                dist[nx][ny][k] = d+1;
                v[nx][ny][k] = 1;
                q.push({nx,ny,k,d+1});
            }
        }
    }
    int mn =(int)1e6+1;

    for (int i=0; i<=mxk; i++)
    {
        int now = dist[row-1][col-1][i];
        if (now != -1 && now <mn) mn=now;
    }
    if (mn==1e6+1) printf("-1\n");
    else printf("%d\n", mn+1);
}
