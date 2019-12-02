#include <bits/stdc++.h>
using ll = long long;

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    stack<int> s;

    while(n--)
    {
        string input;
        cin >> input;

        if ( input == "push"  )
        {
            int m;
            cin >> m;
            s.push(m);
        }
        else if ( input == "pop")
        {
            if ( s.empty() ) cout << "-1\n";
            else 
            {
                cout << s.top() <<"\n";
                s.pop();
            }
        }
        else if (input == "size")
        {
            cout  << s.size() <<"\n";
        }
        else if (input == "empty") cout << s.empty() <<"\n";
        else if (input == "top") 
        {
            if ( s.empty()) cout << "-1\n";
            else cout << s.top() <<"\n";
        }
    }
}
