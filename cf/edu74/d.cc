#include <iostream>
#include <algorithm>
using ll = long long;
using namespace std;

char s[(int)3e5+1];
int num[5];
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    cin >> s; 

    ll val = ((ll)n*(n-1))/2;

    int cnt= 0;
    for (int t=0; t<2; t++)
    {
        cnt =1;
        for (int i=0; i<n-1; i++)
        {
            if ( s[i] == s[i+1])
                cnt++;
            else 
            {
                val -= (cnt-t);
                cnt =1;
            }
        }
        reverse(s, s+n);
    }
    cout << val <<"\n";
}