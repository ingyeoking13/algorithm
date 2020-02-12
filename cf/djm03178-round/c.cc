#include <bits/stdc++.h>
using ll = long long;
using namespace std;

//int t[100], l[100], r[100];
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;

        int cl=m, cr=m;
        int t, l, r; 
        int time = 0;
        bool ans = true;

        for (int i=0; i<n; i++)
        {
            cin >> t >> l >> r;
            int move = t- time;
            time = t;

            cl -= move;
            cr += move;
            if ( cl > r  || cr < l) 
            {
                ans = false;
            }
            if ( cl < l) cl = l;
            if ( cr > r) cr = r;
        }
        cout << (ans?"YES":"NO") << "\n";
    }
}