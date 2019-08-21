#include <iostream>

using namespace std;

int ans[(int)2e5];
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; 
    cin >> n;
    if (n%2 == 0) 
    {
        cout <<"NO\n";
        return 0;
    }

    cout <<"YES\n";

    for (int i=0; i<n; i++)
    {
        if ( i%2==0) 
        {
            ans[i] = 2*i+1;
            ans[n+i] = 2*i+2;
        }
        else
        {
            ans[n+i] = 2*i+1;
            ans[i] = 2*i+2;
        }
    }
    for (int i=0; i<2*n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
}