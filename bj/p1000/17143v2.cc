#include <iostream>
#include <vector>

#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3

using namespace std;

int dx[4]={-1, 0, 1, 0}, dy[4] ={0, 1, 0, -1};

struct shark
{
    int x,y;
    int s, dir, z;
    bool alive;
    shark() {};
};

vector<shark> vrow[100], vcol[100];
int row, col, n;

void moveAll() // 1 sec
{
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<vrow[i].size(); j++)
        {
            shark cur = vrow[i][j];
            if ( !cur.alive) continue;

            cur.y += dy[cur.dir]*cur.s;

            if ( cur.y >= col)
            {
                int diff = cur.y - col+1;
                cur.y = col - diff;
                cur.dir +=2;
                cur.dir %=2;
            }
            else if ( cur.y < 0 )
            {
                int diff = 0 - cur.y;
                cur.y = 0 + diff;
                cur.dir +=2;
                cur.dir %=2;
            }

            vrow[i][j] = cur;
        }
    }

    for (int i=0; i<col; i++)
    {
        for (int j=0; j<vcol[i].size(); j++)
        {
            shark cur = vcol[i][j];
            if ( !cur.alive)  continue;

            cur.x += dx[cur.dir]*cur.s;

            if ( cur.x >= row)
            {
                int diff = cur.x - row+1;
                cur.x = row - diff;
                cur.dir +=2;
                cur.dir %=2;
            }
            else if ( cur.y < 0 )
            {
                int diff = 0 - cur.x;
                cur.x = 0 + diff;
                cur.dir +=2;
                cur.dir %=2;
            }

            vcol[i][j] = cur;
        }
    }

    for (int i=0; i<row; i++)
    {
        for (int j=0;j<vrow[i].size(); j++)
        {
            shark cur = vrow[i][j];
            if ( !cur.alive) continue;

            for (int k=0; k<vrow[i].size(); k++)
            {
                if ( j == k ) continue;
                if ( !vrow[i][k].alive) continue;
                if ( cur.y != vrow[i][k].y ) continue;

                if ( cur.z > vrow[i][k].z)
                {
                    vrow[i][k].alive = false;
                }
                else 
                {
                    cur.alive = false;
                    break;
                }
            }
            vrow[i][j] = cur;

            if ( !cur.alive) continue;

            for (int k=0; k<vcol[cur.y].size(); k++)
            {
                shark tt = vcol[cur.y][k];
                if (!tt.alive) continue;
                if (tt.x != cur.x) continue;
                
                if ( cur.z  > tt.z )
                {
                    vcol[cur.y][k].alive =false;
                }
                else 
                {
                    cur.alive =false;
                    break;
                }
            }
            vrow[i][j] = cur;
        }
    }

    for (int i=0; i<col; i++)
    {
        for (int j=0;j<vcol[i].size(); j++)
        {
            shark cur = vcol[i][j];
            if ( !cur.alive) continue;

            for (int k=0; k<vcol[i].size(); k++)
            {
                if ( j == k ) continue;
                if ( vcol[i][k].alive == false) continue;
                if ( cur.y != vcol[i][k].y ) continue;

                if ( cur.z > vcol[i][k].z)
                {
                    vcol[i][k].alive = false;
                }
                else 
                {
                    cur.alive = false;
                    break;
                }
            }
            vcol[i][j] = cur;

            if (!cur.alive) continue;

            for (int k=0; k<vrow[cur.x].size(); k++)
            {
                shark tt = vrow[cur.x][k];
                if (!tt.alive) continue;
                if (tt.y != cur.y) continue;
                
                if ( cur.z  > tt.z )
                {
                    vrow[cur.x][k].alive =false;
                }
                else 
                {
                    cur.alive =false;
                    break;
                }
            }
            vcol[i][j] = cur;
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> row >> col >> n;

    for (int i=0; i<n; i++)
    {
        shark tmp; 
        cin >> tmp.x >> tmp.y >> tmp.s >> tmp.dir >> tmp.z;

        tmp.y--, tmp.x--, tmp.dir--;

        if (tmp.dir == 1) tmp.dir=2;
        else if (tmp.dir == 2) tmp.dir=1;
        tmp.alive = true;

        if (tmp.dir == 0 || tmp.dir==2) 
        {
            vcol[tmp.y].push_back(tmp);
        }
        else vrow[tmp.x].push_back(tmp);
    }

    int ans =0;
    for (int i=0; i<col; i++)
    {
        int pos = i;

        int mnHeight = 1e9;
        int gotcha = -1;
        for (int j=0; j<vcol[pos].size(); j++)
        {
            if ( vcol[pos][j].alive == false) continue;
            if ( vcol[pos][j].x < mnHeight) 
            {
                mnHeight = vcol[pos][j].x;
                gotcha = j;
            }
        }

        int rowgotcha = -1;
        int rowmnHeight = 1e9;
        for (int j=0; j<row; j++)
        {
            for (int k=0; k<vrow[j].size(); k++)
            {
                if ( vrow[j][k].alive == false) continue;
                if ( vrow[j][k].y == pos)
                {
                    rowmnHeight = j;
                    rowgotcha = k;
                    break;
                }
            }
            if ( rowgotcha >= 0) break;
        }

        if ( gotcha == -1 && rowgotcha == -1);
        else if ( mnHeight < rowmnHeight )
        {
            vcol[pos][gotcha].alive = false;
            ans+= vcol[pos][gotcha].z;
        }
        else 
        {
            vrow[rowmnHeight][rowgotcha].alive = false;
            ans+= vrow[rowmnHeight][rowgotcha].z;
        }

        moveAll();
    }
    cout << ans <<"\n";

}