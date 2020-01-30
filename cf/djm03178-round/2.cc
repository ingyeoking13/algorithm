#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<string> vs;
bool used[100];
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    while(n--)
    {
        string tmp;
        cin >> tmp;
        vs.push_back(tmp);
    }
    n = vs.size();
    int cnt = 0;
    string ans;

    for (int i=0; i<n; i++)
    {
        if ( used[i]) continue;
        string cur = vs[i];

        for (int j=i+1; j<n; j++)
        {
            if ( used[j]) continue;
            string tmp = vs[j];

            reverse(tmp.begin(), tmp.end());
            if ( tmp == cur )
            {
                used[i] = used[j] = true;
                cnt += m*2;
                ans += cur;
                break;
            }
        }
    }


    string add;
    for (int i=0; i<n; i++)
    {
        if ( used[i] ) continue;
        bool isPalin= true;
        for (int j=0; j<m/2; j++)
        {
            if (vs[i][j] != vs[i][m-j-1] ) isPalin =false;
            if ( isPalin == false ) break;
        }
        if ( isPalin) 
        {
            add = vs[i];
            break;
        }
    }

    if (add.size() >0 ) cnt += m;

    cout << cnt <<"\n";
    if ( cnt > 0)
    {
        cout << ans ;
        cout << add;
        reverse(ans.begin(), ans.end());
        cout << ans <<"\n";
    }
}