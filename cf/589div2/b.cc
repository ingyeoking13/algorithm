#include <iostream>

using namespace std;

int r[(int)1e3], c[(int)1e3];
int d[(int)1e3+1][(int)1e3+1];
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i=0; i<n; i++)
        cin >> r[i];

    for (int i=0; i<m; i++)
        cin >> c[i];

    for (int i=0; i<n; i++)
    {
        if ( r[i] == 0) 
            d[i][0] = -1; 
        else 
        {
            for (int j=0; j<r[i]; j++) d[i][j] =1;
            d[i][r[i]] = -1;
        }
    }

    bool fu = false;
    for (int i=0; i<m; i++)
    {
        if ( c[i] == 0)
        {
            if ( d[0][i] > 0) fu = true;
            d[0][i] = -1;
        }
        else 
        {
            for (int j=0; j<c[i]; j++)
            {
                if ( d[j][i] == -1 ) fu =true;
                d[j][i] = 1;
            }
            if ( d[c[i]][i] > 0)  fu =true;
            d[c[i]][i] = -1;
        }
    }

    if ( fu ) 
    {
        cout  << 0 <<"\n";
        return 0;
    }
    long long hit =1;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if (d[i][j] == 0) hit*=2;
            hit%= (long long)(1e9+7);
        }
    }

    cout << hit <<"\n";
} 