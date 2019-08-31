#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[10];
bool vis[10];
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=1; i<10; i++)
    {
        memset(vis, 0, sizeof(vis));

        int next = i;
        while(!vis[next]) 
        {
            vis[next]= true;
            v[i].push_back(next);

            next+=i;
            next%=10;
        }
    }

    int q;
    cin >> q;
    while(q--)
    {
        long long n, m;
        cin >> n >> m;

        long long cnt = n/m;

        m = m%10;
        long long sz = v[m].size();
        if( sz == 0)
        {
            cout << "0\n";
            continue;
        }

        long long ans = 0;

        long long sum = 0;
        for (int i=0; i<sz; i++)
        {
            sum += v[m][i];
        }
        ans += sum*(cnt/sz);

        cnt = cnt%sz;
        for (int i=0; i<cnt; i++)
        {
            ans += v[m][i];
        }
        cout << ans <<"\n";
    }
}