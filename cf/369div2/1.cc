#include <bits/stdc++.h>
using ll = long long;
using namespace std;

char s[1000][8];
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i=0; i<n; i++)
        cin >> s[i];


    bool find = false;
    for (int i=0; i<n; i++)
    {
        if ( s[i][0] == s[i][1] && s[i][1] == 'O')
        {
            s[i][0] = s[i][1] = '+';
            find = true;
            break;
        }

        if ( s[i][3] == s[i][4] && s[i][3] == 'O')
        {
            s[i][3] = s[i][4] = '+';
            find = true;
            break;
        }
    }

    if( find ) 
    {
        cout << "YES\n";
    for (int i=0; i<n; i++)
        cout << s[i] << "\n";
    }
    else cout << "NO\n";

}