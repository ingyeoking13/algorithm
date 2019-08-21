#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
struct pos
{
    int x, y;
    pos(int x, int y ) : x(x), y(y) {};
};

vector<pos> v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i=0; i<n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    double ans = 1e9;
    pos aans = pos(-1, -1);
    for (int i=0; i<n-1; i++)
    {
        long long most = 0;
        pos cur = v[i];
        for (int j=i+1; j<n; j++)
        {
            pos next = v[j];
            long long dist = (cur.x - next.x) * (cur.x - next.x)
            + (cur.y - next.y ) * (cur.y - next.y);
            if ( dist  > most) 
            {
                most = dist;
            }
        }
        if ( ans > most )
        {
            ans = most;
            aans = cur;
        } 
    }
    cout << aans.x << " " << aans.y <<"\n";
}