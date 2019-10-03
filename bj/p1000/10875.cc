#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
struct point 
{
    int x, y;
    point() {} ;
    point(int x, int y ) : x(x),y(y) {};
    point operator-(point o) { return point( x-o.x, y-o.y);};
    long long operator*(point o) { return (double)x*o.y - (double)y*o.x; }
    bool operator<(point o)
    { 
        if ( x== o.x ) return y < o.y;
        return x < o.x;
    }
};
struct line
{
    point sp, ep;
    line () {};
    line (point sp, point ep) : sp(sp), ep(ep) {};
};

bool intersect(line a, line b) 
{
    point p1 = a.sp, p2 = a.ep;
    point pp1 = b.sp, pp2 = b.ep;

    if ( p2 < p1 ) 
    {
        point tmp = p1;
        p1 = p2;
        p2 = tmp;
    }
    if ( pp2 < pp1 )
    {
        point tmp = pp1;
        pp1 = pp2;
        pp2 = tmp;
    }

    int ret = false;

    point i =  p1-p2, j = pp1 - p1, k = pp2 - p1;

    long long val = i*j;
    long long val2 = i*k;

    if ( val >0 ) val =1;
    else if ( val <0 ) val=-1;

    if ( val2 >0 ) val2 =1;
    else if ( val2 <0 ) val2 =-1;
    long long tmp = val*val2;

    point ii = pp1 -pp2, jj =  p1-pp1, kk = p2 - pp1;
    val = ii*jj;
    val2 = ii*kk;

    if ( val >0 ) val =1;
    else if ( val <0 ) val=-1;

    if ( val2 >0 ) val2 =1;
    else if ( val2 <0 ) val2 =-1;

    long long tmp2 = val*val2;

    if ( tmp == 0 && tmp2 == 0)
        ret = !(pp2 <p1 || p2 < pp1);
    else if ( tmp<= 0 && tmp2 <= 0)
        ret = true;

    return ret;
};

vector<line> v;  
int dy[ 4 ] =  {1, 0, -1, 0}, dx [ 4 ] = {0, 1, 0, -1} ;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    char in[2];
    int t;

    int sx = 0, sy = 0;
    int dir = 0;

//좌
    v.push_back({point(-n-1,-n-1),point(n+1,-n-1)});
//하 
    v.push_back({point(-n-1,-n-1),point(-n-1,n+1)});
//우 
    v.push_back({point(n+1,n+1),point(-n-1, n+1)});
//상
    v.push_back({point(n+1,n+1),point(n+1, -n-1)});

    long long ans = 0;

    for (int i=0;i<=m;i++)
    {
        if ( i == m) t= 2e8+1;
        else cin >> t >> in;

        int ex = sx+ dx[ dir ] * t;
        int ey = sy+ dy[ dir ] * t;

        line l;
        if ( i ==0 )
            l = line({point(sx, sy), point(ex, ey)});
        else 
            l = line({point(sx+dx[dir], sy+dy[dir]), point(ex, ey)});

        int mmin= 1e9;
        for (auto l2 : v)
        {
            if ( intersect(l,l2) ) 
            {
                int curx = sx, cury = sy;
                if ( dir == 0 || dir == 2) // 가로 이동 
                    mmin = min({abs(cury-l2.sp.y), abs(cury-l2.ep.y), mmin});
                else 
                    mmin = min({abs(curx-l2.sp.x), abs(curx-l2.ep.x), mmin});
            };
        }

        if (mmin <1e9 )
        {
            cout << ans +mmin <<"\n";
            return 0;
        }
        v.push_back(l);

        sx = ex;
        sy = ey;

        ans += t;

        if ( in[0] == 'L') dir = (dir+3)%4;
        else dir = (dir+1)%4;
    }
}