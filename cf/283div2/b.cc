#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using ll = long long;
using namespace std;

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    int n;
    cin >> n >> str;

    string ans =str;
    queue<string> q;
    q.push(str);

    set<string> s;

    for (int i=0; i<n; i++)
    {
        string val;
        for (int j=0; j<n; j++)
        {
            int diff = str[(i + j)%n]- str[i];
            if (diff <0 ) diff+=10;

            string add;
            add.resize(1);
            add[0] = '0'+diff;
            val +=  add;
        }
        ans = min(val, ans);
    }
    cout<< ans<<"\n";

}