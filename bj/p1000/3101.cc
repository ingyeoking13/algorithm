#include <iostream>

using namespace std;
char s[(int)3e5+1];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k; 
    cin >> n >> k;
    cin >> s;
    long long ans = 1;

    int x=1, y=1;
    int state = 0;

    for (int i=0; i<k; i++)
    {
        char c = s[i];

        if ( c == 'D') x++;
        else if ( c== 'U') x--;
        else if ( c == 'R') y++;
        else y--;

        state++;
        long long level = x+y-1;
        if ( level <= n)
        {
            level=(level*(level+1))/2;
            int diff;
            if ( state % 2 )
                diff = y - 1; 
            else 
                diff = x -1;
            ans += (level - diff);
        }
        else 
        {
            long long inverse = 2*n-1 -level;

            level = (long long)n*n;
            level -= (inverse*(inverse+1))/2;

            int diff;
            if ( state % 2 )
                diff = n-x;
            else 
                diff = n-y;
    //        cout << "level "  <<  level << " diff " << diff <<"\n";
            ans += (level - diff);
        }

     //   cout << ans << "\n";
    }
    cout << ans <<"\n";
}