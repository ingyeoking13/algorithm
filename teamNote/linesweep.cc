/* baekjoon https://www.acmicpc.net/problem/2261 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>

using namespace std;

struct vec2d 
{
    int x, y; 
    bool operator< (const vec2d& o) const
    {
        return y < o.y;
    }
};

int dist (vec2d x, vec2d y)
{
    return (x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y);
}

bool cmp(vec2d x, vec2d y)
{
    return x.x < y.x;
}

int main()
{
    vector<vec2d> v;
    int n;
    cin >> n;

    for (int i=0; i <n ;i++)
    {
        int x, y;
        cin >>  x>> y ;
        v.push_back({x,y});
    }
    sort(v.begin(), v.end(), cmp);

    int ans = dist(v[0], v[1]);
    set<vec2d> cand= { v[0], v[1]};
    int start = 0;
    for (int i=2; i<n; i++)
    {
        vec2d cur = v[i];
        while( start < i)
        {
            int x = cur.x - v[start].x;
            if ( x*x > ans )
                cand.erase(v[start]);
            else break;
            start++;
        }

        int d = (int)sqrt((double)ans)+1;
        vec2d lpoint = { -1e5 , cur.y-d };
        vec2d rpoint = { 1e5 , cur.y+d };
        auto lit = cand.lower_bound( lpoint );
        auto rit = cand.upper_bound( rpoint );
        while (lit != rit)
        {
            int d = dist( cur , *lit );
            if ( d < ans )
                ans = d;
            lit++;
        }
        cand.insert(cur);
    }
    cout << ans << "\n";
}