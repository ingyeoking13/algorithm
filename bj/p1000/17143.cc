#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };

struct shark
{
	int x, y, s, dir, z;
    bool alive;
	shark() {};
};

int row, col, n;
vector<shark> v;
int a[100][100][2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

//	freopen("input.txt", "r", stdin);

	cin >> row >> col >> n;
    memset(a, -1, sizeof(a));

	for (int i = 0; i < n; i++)
	{
		shark tmp;
		cin >> tmp.x >> tmp.y >> tmp.s >> tmp.dir >> tmp.z;

		tmp.y--, tmp.x--, tmp.dir--;

		if (tmp.dir == 1) tmp.dir = 2;
		else if (tmp.dir == 2) tmp.dir = 1;

        tmp.alive =true;
		v.push_back(tmp);
		a[tmp.x][tmp.y][0] = i;
	}

	int ans = 0;
	for (int i = 0; i < col; i++)
	{
       
        for (int j=0; j<row; j++)
        {
            if ( a[j][i][i%2] >= 0 )
            {
                int id = a[j][i][i%2];
                ans += v[id].z;
                a[j][i][i%2] = -1;
                v[id].alive = false;
                break;
            }
        }


        for (int j=0; j<v.size(); j++)
        {

            shark& cur = v[j];
            if ( cur.alive == false) 
            {
                continue;
            }

            a[cur.x][cur.y][i%2] = -1;

            int tmp = cur.s;
            if ( cur.dir == 0 || cur.dir == 2) tmp%=(row*2-2);
            else tmp%=(col*2-2);

            while(tmp)
            {
                int nx = cur.x + dx[cur.dir];
                int ny = cur.y + dy[cur.dir];

                if ( nx <0 || ny <0 || nx >= row || ny >= col)
                {
                    cur.dir += 2;
                    cur.dir %=4;
                }
                cur.x += dx[cur.dir];
                cur.y += dy[cur.dir];
                tmp--;
            }

            int id = a[cur.x][cur.y][(i+1)%2];

            if ( id >= 0 && v[id].z > v[j].z)
            {
                v[j].alive = false;
            }
            else 
            {
                a[cur.x][cur.y][(i+1)%2] = j; 
                if(id >=0 ) v[id].alive = false;
            }
        }
	}
	cout << ans << "\n";
}