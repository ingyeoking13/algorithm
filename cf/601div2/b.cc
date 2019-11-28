#include <bits/stdc++.h>
using ll = long long;
using namespace std;

pair<int,int> cost[(int)1e3];
int ind[(int)1e3], outd[(int)1e3];
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


        for (int i=0; i<n; i++)
        {
            cin >> cost[i].first;
            cost[i].second = i+1;
        }

        if ( n== 2 || m < n )
        {
            cout << "-1\n";
            continue;
        }

        sort(cost, cost+n);

        ll ans =0;
        for (int i=0; i<n; i++)
        {
            ans += (cost[i].first + cost[(i+1)%n].first);
        }
        int cc = m-n;
        while (cc--) ans += (cost[0].first + cost[1].first);
        cout << ans << "\n";

        ll tmp = 1e9;
        if ( m >= (n-2)*2+1)
        {
            tmp = 0;
            tmp += cost[0].first + cost[1].first;
            for (int i=2; i<n; i++) 
            {
                tmp += cost[0].first + cost[i].first;
                tmp += cost[1].first + cost[i].first;
            }
            cc = m-((n-2)*2+1);
            while( cc--) tmp += (cost[0].first + cost[1].first);

            if ( tmp < ans)
            {
                cout << tmp <<"\n";

                cout << cost[0].second << " " << cost[1].second << "\n";
                for (int i=2; i<n; i++)
                {
                    cout << cost[0].second << " " << cost[i].second << "\n";
                    cout << cost[1].second << " " << cost[i].second << "\n";
                }
                cc = m-((n-2)*2+1);
                while(cc--)  cout << cost[0].second << " "<< cost[1].second << "\n";
                continue;

            }
        }

        for (int i=1; i<=n-1; i++)
        {
            cout << i << " " << i+1 <<"\n";
        }
        cout << n << " " << 1 <<"\n";
        m -=n;
        while( m--) cout << cost[0].second << " " << cost[1].second << "\n";
        

    }

}