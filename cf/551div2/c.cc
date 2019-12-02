#include <bits/stdc++.h>
using ll = long long;
using namespace std;

char c[(int)3e5+1];
char ans[(int)3e5+1];
int cnt[(int)3e5];
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    cin >> c;

    if ( n%2 )
    {
        cout << ":(\n";
        return 0;
    }

    int d[3]= {0,0,0};
    for (int i=0; i<n; i++)
    {
        if ( c[i] == '(') d[0]++;
        else if ( c[i]==')') d[1]++;
        else d[2]++;
    }

    int myOpen = d[0]-d[1];
    myOpen = (d[2] - myOpen)/2;

    int curval=0;

    for (int i=0; i<n; i++)
    {
        if ( c[i] == '?')
        {
            if (myOpen)
            {
                ans[i] = '(';
                curval++;
                myOpen--;
            }
            else 
            {
                ans[i] = ')', curval--;
                if ( curval <= 0 && i != n-1)
                {
                    cout << ":(\n";
                    return 0;
                }
            }
        }
        else 
        {
            ans[i] = c[i];
            if ( c[i] =='(')
                curval++;
            else
            {
                curval--;
                if ( curval <= 0 && i!=n-1)
                {
                    cout <<":(\n";
                    return 0;
                }
            }
        }
    }

    if (curval !=0 )
    {
        cout << ":(\n";
    }
    else cout << ans <<"\n";


}