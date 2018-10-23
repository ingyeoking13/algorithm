#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

char s[100][101];
int vis[100][100]; // 3d 0~4 -> 0~3 searching dir , 4 init state 
int dx[4] ={-1, 0, 1, 0}, dy[4] ={0, -1, 0, 1};

struct status
{
    int x, y;
    status(int x, int y) : x(x), y(y) {}
};
pair<int, int> pre[100][100];

int main()
{
    int row, col;
    scanf("%d%d", &col, &row);
    for (int i=0; i<row; i++) scanf("%s", s[i]);
    memset(pre,-1, sizeof(pre));

    pair<int, int> st = {-1, -1}; // start point
    pair<int, int> en = {-1, -1}; // end point
    memset(vis, -1, sizeof(vis));

    // set start, end  point 
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            if (st.first == -1 && s[i][j] =='C')  st= {i, j};
            else if (s[i][j]=='C') en = {i, j};
        }
    }

    //init queue
    queue<status> q;
    vis[st.first][st.second]=0;
    q.push({st.first, st.second});

    //searching start
    while(!q.empty())
    {
        auto now = q.front();
        q.pop();
        for (int i=0; i<4; i++)
        {
            int nx = now.x+dx[i], ny = now.y+dy[i];

            while (nx >=0 && nx < row && ny >= 0 && ny < col)
            {
                if (s[nx][ny]!= '*')
                {
                    if (vis[nx][ny]==-1)
                    {
                        vis[nx][ny]=vis[now.x][now.y]+1;
                        q.push({nx, ny});
                        pre[nx][ny] = {now.x, now.y};
                    }
                }
                else break;
                nx += dx[i], ny += dy[i];
            } 
        }
    }

    printf("%d\n", vis[en.first][en.second]-1);
}
