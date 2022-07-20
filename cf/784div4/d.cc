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
    while(t--) {
        int n;
        cin >> n;
        string str;
        cin >> str;
        int i = 0;

        while(i<n && str[i] == 'W') {
            i++;
        }
        if (i == n) 
        {
            cout << "YES\n";
            continue;
        }

        int ans = 1;
        while (i < n) {
            int j = i;
            while(j< n && str[j] != 'W') j++;

            int count[2] ={0, 0};
            for (int k=i; k<j; k++) {
                if (str[k] == 'B')count[0]++;
                else count[1]++;
            }
            if (count[0]==0 || count[1] == 0) ans = 0;
            while(j< n && str[j]=='W') j++;
            i=j;
        }
        cout << (ans?"YES":"NO")<<"\n";
    }
}