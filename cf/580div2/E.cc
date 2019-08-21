#include <iostream>
#include <string.h>

using namespace std;

int ans[51][51];
int main ()
{
    /*
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    */

    int n;
    cin >>n;

    for (int i=1; i<=n; i++) ans[i][1] = 1;

    cout << "? 1 1 1 3\n";
    cout.flush();
    int tmp;
    cin >> tmp;
    if (tmp) ans[1][3] = ans[1][1];
    else ans[1][3] = -ans[1][1];

    cout << "? 2 1 2 3\n";
    cout.flush();

    cin >> tmp;
    if (tmp) ans[2][3] = ans[2][1];
    else ans[2][3] = -ans[2][1];

    cout << "? 3 1 3 3\n";
    cout.flush();

    cin >> tmp;
    if (tmp) ans[3][3] = ans[3][1];
    else ans[3][3] = -ans[3][1];

    cout << "? 1 1 3 1\n";
    cout.flush();

    cin >> tmp;
    int bef = ans[3][1];

    if ( tmp ) ans[3][1] = ans[1][1];
    else ans[3][1] = -ans[1][1];

    if ( bef != ans[3][1]) ans[3][3] = -ans[3][3];

    cout << "? 1 1 2 2\n";
    cout.flush();
    cin >> tmp;

    if (tmp) ans[2][2] = ans[1][1];
    else ans[2][2] = -ans[1][1];

    cout << "? 2 2 3 3\n";
    cout.flush();
    cin >> tmp;

    bef = ans[3][3];
    if (tmp ) ans[3][3] = ans[2][2];
    else ans[3][3] = -ans[2][2];

    if ( bef != ans[3][3])
    {
        ans[3][1] = -ans[3][1];
    }

    cout << "? 2 1 3 2\n";
    cout.flush();

    cin >> tmp;
    bef = ans[2][1];

    if (tmp)  ans[2][1] = ans[3][2];
    else ans[2][1] = -ans[3][2];

    if (bef != ans[2][1])
    {
        ans[2][3] = -ans[2][3];
    }

    cout << "? 1 2 2 3\n";
    cout.flush();
    
    cin >> tmp;

    if (tmp) ans[1][2] = ans[2][3];
    else ans[1][2] = -ans[2][3];

    for (int i=1; i<=3; i++)
    {
        for (int j=2; j+2 <=n; j++ )
        {
            cout << "? " << i << " "  << j << " " << i << " " << j+2 << "\n";
            cout.flush();
            int ret;
            cin >> ret;
            if (ret) ans[i][j+2] = ans[i][j];
            else ans[i][j+2] = -ans[i][j];
        }
    }

    for (int i=1; i<=3; i++)
    {
        for (int j=2; j+2 <=n; j++ )
        {
            cout << "? " << j << " "  << i << " " << j+2 << " " << i << "\n";
            cout.flush();
            int ret;
            cin >> ret;
            if (ret) ans[j+2][i] = ans[j][i];
            else ans[j+2][i] = -ans[j][i];
        }
    }

    for (int i=4; i<=n; i++)
    {
        for (int j=2; j+2<=n; j++)
        {
            cout << "? " << i << " "  << j << " " << i << " " << j+2 << "\n";
            cout.flush();
            int ret;
            cin >> ret;
            if (ret) ans[i][j+2] = ans[i][j];
            else ans[i][j+2] = -ans[i][j];
        }
    }

    cout << "!\n";
    cout.flush();
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            cout << (int)(ans[i][j]==1?1:0);
        }
        cout <<"\n";
    }
    cout.flush();
}