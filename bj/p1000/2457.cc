#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Date
{
    int sm,sd, em, ed;
    Date(int sm, int sd, int em, int ed) : 
        sm(sm), sd(sd), em(em), ed(ed) {};
    bool operator< (Date b) 
    {
        if ( sm == b.sm)
        {
            if ( sd == b.sd)
            {
                if ( em == b.em) return ed < b.ed;
                return em < b.em;
            }
            return sd < b.sd;
        }
        return sm< b.sm;
    };
};

vector<Date> v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        v.push_back({a, b, c, d});
    }
    sort(v.begin(), v.end());

    int s = 0;
    int mm = 3, dd = 1;
    int ans = 0;
    while (true)
    {
        if ( mm == 12 ) break;
        if ( s== n) 
        {
            ans = 0;
            break;
        }
        int lm= -1, ld=-1;
        for (; s<n; s++)
        {
            if ( v[s].sm == mm && v[s].sd <= dd);
            else if ( v[s].sm <mm );
            else { s--; break; }

            if ( v[s].em > lm) 
            {
                lm = v[s].em ;
                ld = v[s].ed ;
            }
            else if ( v[s].em == lm && v[s].ed >= ld )
            {
                lm = v[s].em;
                ld = v[s].ed;
            }
        }
        mm = lm, dd =ld;
        ans++;
    }
    cout << ans <<"\n";
}