#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int a[(int)2e5];

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> cnt(n, 0);
        priority_queue<pair<int,int>> pq;
        vector<int> peg[(int)2e5];

        int mx = 0, m = -1;

        for (int i =0; i<n; i++ )
        {
            cin >> a[i];
            a[i]--;
            cnt[ a[i] ]++;
            peg[a[i]].push_back(i);
        }

        for (int i=0; i<n; i++) 
        {
            if ( cnt[i] <= 1) continue;
            pq.push({cnt[i], i});
        }

        int ans = 1e9;
        while (!pq.empty())
        {
            int m = pq.top().second;
            int tmp = pq.top().first;
            pq.pop();

            int l = 2, r = tmp;
            for (int j= l; j<=min(r, ans); j++)
            {
                int mid = j; 
                bool find = false;

                for (int i=0;i<tmp; i++)
                {
                    int st = peg[m][i];
                    if ( i + mid -1 >= tmp) break;
                    int ed = peg[m][i+ (mid-1) ];
                    if ( ed- st +1 >= ans) continue;

                    int tmx=0, tm= -1;
                    vector<int> ccnt(n, 0);
                    bool dup = false;
                    for (int i=st; i<=ed; i++)
                    {
                        ccnt[a[i]]++;

                        if ( tmx == ccnt[a[i]]) dup = true;
                        else if ( tmx < ccnt[ a[i] ] ) 
                        {
                            tmx = ccnt[ a[i] ], tm = a[i];
                            dup =false;
                        }
                    }

                    if ( dup );
                    else if ( tm == m ) 
                    {
                        find = true, ans = min(ans, ed-st+1);
                    }
                }
                if ( find) break;
            }
        }

        if ( ans == 1e9) ans = -1;
        cout << ans <<"\n";

    }
}