#include <iostream>
#include <algorithm>

using namespace std;
char s[20002];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, r1, c1, r2, c2;
    cin >> n >> r1 >> c1 >> r2 >> c2;

    for (int row =r1; row<=r2; row++)
    {
        int x = row%(2*n-1);
        int xdist = abs(x - (n-1));
        int len = n-xdist;
        for (int col=0; col<=c2; col++)
        {
            int y = col%(2*n-1);
            int ydist = abs(y - (n-1));

            if ( ydist <len ) s[col] = (ydist + xdist)%26 + 'a';
            else s[col] = '.';
        }
        s[c2+1]=0;
        cout << s+c1 <<"\n";
    }
}