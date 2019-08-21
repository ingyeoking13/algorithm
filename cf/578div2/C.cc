#include <iostream>

using namespace std;

long long gcd(long long a, long long b)
{
    return b?gcd(b, a%b):a;
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n, m;
    int T;
    cin >> n >> m >> T;

    long long g= gcd(n, m);

    while(T--)
    {
        long long sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        sy--, ey--;

        if ( g == 1 )
        {
            cout << "YES\n";
            continue;
        }

        if ( sx == 1 && ex == 1 )
        {
            long long ibase = n/g;
            if (sy /ibase == ey/ibase)
            {
                cout << "YES\n";
            }
            else cout <<"NO\n";

        }
        else if ( sx ==2 && ex == 2 )
        {
            long long obase = m/g;
            if ( sy / obase == ey/obase)
            {
                cout <<"YES\n";
            }
            else cout <<"NO\n";
        }
        else
        {
            if ( sx == 2 )
            {
                long long tmp = sx;
                sx = ex;
                ex = tmp;

                tmp = sy;
                sy = ey;
                ey = tmp;
            }

            long long ibase = n/g;
            long long obase = m/g;
            if ( sy/ibase  == ey/obase )
            {
                cout <<"YES\n";
            }
            else cout <<"NO\n";
        }
    }
}