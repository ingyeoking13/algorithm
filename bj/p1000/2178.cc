#include <iostream>
#include <string.h>
#include <queue>

using namespace std;
char map[100][101];
int d[100][100];
int dx[4]={-1, 1, 0, 0}, dy[4]={0, 0, -1, 1};

struct pos{
    int x, y;
    pos(int x, int y): x(x), y(y) {};
    pos(){};
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int row, col; 
    cin >> row >> col;
    for (int i=0; i<row; i++)
    {
        cin >> map[i];
    }
    queue<pos> q;
    q.push({0, 0});
    d[0][0] = 1;

    while(!q.empty())
    {
        pos cur = q.front();
        q.pop();
        int x = cur.x, y = cur.y;

        for (int i =0; i<4; i++)
        {
            int nx = x+dx[i], ny = y+dy[i];
            if ( nx < 0 || ny <0 || nx >= row || ny >= col) continue;
            if ( map[nx][ny] == '0' ) continue;
            if ( d[nx][ny] > 0) continue;
            d[nx][ny] = d[x][y] +1;
            q.push({nx, ny});
        }
    }
    cout << d[row-1][col-1] <<"\n";
}