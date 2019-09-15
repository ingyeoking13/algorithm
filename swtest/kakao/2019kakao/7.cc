#include <string>
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct state
{
    int x, y, dir;
    state(int x, int y, int dir) : x(x), y(y), dir(dir) {};
};

int d[100][100][2]; // 0 가로 -좌측 포지션 , 1 세로 - 위쪽 포지션 
int dx[4] ={-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int solution(vector<vector<int>> board) {
    
    int row = board.size(), col = board[0].size();
    memset(d, -1, sizeof(d));
    
    int answer = 1e9;
    queue<state> q;
    q.push({0, 0, 0});
    d[0][0][0] = 0;
    while(!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int x = cur.x, y= cur.y, dir = cur.dir;
        //cout << x << " " << y << " " << dir << "\n";
        if ( dir == 0 )
        {
            for (int i=0; i<4; i++)  // 위상변화 X 
            {
                int nx = x+dx[i], ny= y +dy[i];
                if ( nx < 0 || nx >= row || ny < 0 || ny+1 >= col )  continue;
                if ( board[nx][ny]  || board[nx][ny+1] ) continue;
                if ( d[nx][ny][dir] >= 0) continue;
                d[nx][ny][dir]  = d[x][y][dir] +1;
                q.push({nx, ny, dir});
            }
            
            // 위상변화 set 
            // 좌측 기준, 우측 왼위로 보냄 
            int nx = x-1, ny = y, ndir = 1;
            
            if ( nx >= 0 && board[nx][ny] == 0 && d[nx][ny][ndir] < 0)
            {
                if ( board[x-1][y+1] == 0 ) 
                {
                    d[nx][ny][ndir] = d[x][y][dir]+1;
                    q.push({nx, ny, ndir});
                }
            }
            
            // 좌측 기준, 우측 왼아래로 보냄 
            nx = x, ny =y , ndir =1;
            if ( x +1 < row && board[x+1][y] == 0 && d[nx][ny][ndir] < 0 )
            {
                if ( board[x+1][y+1] == 0 ) 
                {
                    d[nx][ny][ndir] = d[x][y][dir]+1;
                    q.push({nx, ny, ndir});
                }
            }
            
            // 우측 기준, 좌측 우위로 보냄 
            nx = x-1, ny =y+1 , ndir =1;
            if ( nx >= 0 && board[nx][ny] == 0 && d[nx][ny][ndir] < 0 ) 
            {
                if ( board[x-1][y] == 0 ) 
                {
                    d[nx][ny][ndir] = d[x][y][dir]+1;
                    q.push({nx, ny, ndir});
                }
            }
            
            // 우측 기준, 좌측 우아래로 보냄 
            nx = x, ny =y+1 , ndir =1;
            if ( x+1 < row  && board[x+1][y+1] == 0 && d[nx][ny][ndir] < 0 ) 
            {
                if ( board[x+1][y] == 0 ) 
                {
                    d[nx][ny][ndir] = d[x][y][dir]+1;
                    q.push({nx, ny, ndir});
                }
            }
        }
        else  // 세로 버전 
        {
            for (int i=0; i<4; i++)  // 위상변화 X 
            {
                int nx = x+dx[i], ny= y +dy[i];
                if ( nx < 0 || nx+1 >= row || ny < 0 || ny >= col )  continue;
                if ( board[nx][ny]  || board[nx+1][ny] ) continue;
                if ( d[nx][ny][dir] >= 0) continue;
                d[nx][ny][dir]  = d[x][y][dir] +1;
                q.push({nx, ny, dir});
            }
            
            // 위상변화 set 
            // 위 기준, 아래 위왼쪽으로 보냄 
            int nx = x, ny = y-1, ndir = 0;
            
            if ( ny >= 0 && board[nx][ny] == 0 && d[nx][ny][ndir] < 0 )
            {
                if ( board[ x +1 ][ y -1 ] == 0 )
                {
                    d[nx][ny][ndir] = d[x][y][dir]+1;
                    q.push({nx, ny, ndir});
                }
            }
            
            // 위 기준, 아래 위우측으로 보냄
            nx = x, ny = y , ndir =0;
            if (  ny +1 < col && board[nx][ny+1] == 0 && d[nx][ny][ndir] < 0 )
            {
                if ( board[x+1][y+1] == 0 ) 
                {
                    d[nx][ny][ndir] = d[x][y][dir]+1;
                    q.push({nx, ny, ndir});
                }
            }
            
            // 아래 기준, 위 아래왼쪽으로 보냄 
            nx = x+1, ny =y-1 , ndir =0;
            if ( ny >= 0 && board[nx][ny] == 0 && d[nx][ny][ndir] < 0 )
            {
                if ( board[x][y-1] == 0 ) 
                {
                    d[nx][ny][ndir] = d[x][y][dir]+1;
                    q.push({nx, ny, ndir});
                }
            }
            
            //  아래 기준, 위 아래우측으로 보냄 
            nx = x+1, ny =y , ndir =0;
            if ( ny +1 < col && board[nx][ny+1] == 0 && d[nx][ny][ndir] < 0) 
            {
                if ( board[x][y+1] == 0) 
                {
                    d[nx][ny][ndir] = d[x][y][dir]+1;
                    q.push({nx, ny, ndir});
                }
            }
        }
    }
    
    int sero = d[row-2][col-1][1];
    int garo = d[row-1][col-2][0];
    if ( sero > 0 ) answer = sero;
    if (garo >0 ) answer = min(answer, garo);
    return answer;
}