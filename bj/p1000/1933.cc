#include <bits/stdc++.h>
using ll = long long;

using namespace std;

struct node
{
    int x, y, h;
    node( int x, int y, int h ) : x(x), y(y), h(h) {};
    node() {};
    bool operator< (node o)
    {
        return  x< o.x;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    node a[(int)1e5];
    for (int i=0; i<n; i++)
    {
        cin >> a[i].x >> a[i].y >> a[i].h;
    }

    sort(a, a+n);

    priority_queue<pair<int, int>> pq;
    map<int, int> ans;

    int mxid = -1;
    for (int i=0; i<n; i++)
    {
        if (pq.size() == 0)
        {
            ans[a[i].x] = a[i].h;
        }
        else 
        {
            pair<int,int> cur = pq.top();
            int y = -cur.first;

            if ( y <= a[i].y)
            {
                if ( mxid == cur.second) 
                {
                    mxid = 

                }
                pq.pop();
            }
            else 
            {
            }



        }

    }
}