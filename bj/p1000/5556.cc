#include <iostream>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;

    cin>> n >> q;
    while(q--)
    {
        int x, y;
        cin >> x >> y;

        y = n -y;
        y++;

        if ( y > x)
        {
            int tmp = x;
            x= y;
            y = tmp;
        }

        if ( -x + n < y)
        {
            int diff = y -(n - x + 1);
            y -= diff;
            x -= diff;
        }

        int ans = y%3;
        if (ans ==0) ans=3;
        cout << ans <<"\n";
    }

}