#include <iostream>

using namespace std;

int a[(int)2e5];
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i=0; i<n; i++) 
    {
        cin >> a[i];
    }

    int q;
    cin >> q;
    for (int i=0; i<q; i++)
    {
        int o;
        cin >> o;

        if ( o == 1)
        {
            int p, x;
            cin >> p >> x;
        }
        else 
        {
            int x;
            cin >> x;
        }
    }
}