#include <iostream>
#include <string>

using ll = long long;
using namespace std;

char s[100][101];
string st[100];
bool b[100];
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int row, col;
    cin >> row >> col;

    for (int i=0; i<col; i++) b[i]= true;

    for (int i=0; i<row; i++)
        cin >> s[i];

    bool wrong = true;
    bool state = true;
    int ans =0;

    for (int j=0; j<col; j++)
    {
        if ( b[j]==0) continue;
        wrong = false;

        for (int i=1; i<row; i++)
        {
            if( st[i] == st[i-1])
            {
                if ( s[i][j] < s[i-1][j])
                {
                    b[j] = 0;
                    j=0;
                    ans++;
                    wrong = true;
                    break;
                }
            }
        }

        if (!wrong )
        {
            for (int i=0; i<row; i++)
            {
                st[i] += s[i][j];
            }
        }
    }

cout << ans<<"\n";

}