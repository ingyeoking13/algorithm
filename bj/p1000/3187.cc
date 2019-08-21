#include <iostream>

using namespace std;
char s[250][251];
bool v[250][250];

int row, col;
int dx[4]  ={-1, 1, 0 , 0}, dy[4] ={0, 0, -1, 1};

int sheep, wolf;

void go(int x, int y)
{
    v[x][y] = true;
    if ( s[x][y] =='v' ) wolf++;
    if ( s[x][y] =='k') sheep++;

    for (int i=0; i<4; i++)
    {
        int nx =  x+dx[i], ny = y+dy[i];
        if ( nx <0 || ny <0 || nx>=row || ny>=col ) continue;
        if ( v[nx][ny] ) continue;
        if ( s[nx][ny] == '#') continue;

        go(nx, ny);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> row >> col;
    for (int i=0; i<row; i++)
    {
        cin >> s[i];
    }

    int ansSheep=0, ansWolf=0;
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            if ( s[i][j] == '.') continue;
            if( v[i][j]) continue;
            sheep  = wolf = 0;
            go(i, j);
            if ( sheep > wolf)
            {
                ansSheep += sheep;
            }
            else ansWolf += wolf;
        }
    }

    cout << ansSheep << " " << ansWolf <<"\n";
}