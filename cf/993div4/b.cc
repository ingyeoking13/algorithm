#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        string ans="";

        for (int i=s.size()-1; i>=0; i--) {
            char c = s[i];
            char d;
            if (c == 'p') d='q';
            else if (c=='w') d='w';
            else d='p';
            ans += d;
        }
        cout << ans <<"\n";
    }

}