// failed
#include <bits/stdc++.h>
using ll = long long;

using namespace std;
int u[9], v[9];
int state[10];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=0; i<9;  i++)
    {
        cin >> u[i] >> v[i];
        if ( u[i] == 1 ) u[i] =2;
        else u[i] = 1;
    }

    int chi = 0;
    for (int i=1; i<=9; i++)  
       chi |= u[i];
    if ( chi == 1 ) 
    {
        cout << "-1\n";
        return 0;
    }

    int ans = -1;
    for (int i=0; i<9; i++)
    {
        for (int j=1; j<=9; j++) state[j] = 0;

        bool stateduplicate = false;
        u[i] ^= 1;

        for (int j=0; j<9; j++)
            state[ v[j] ] |= u[j];

        for (int j=1; j<=9; j++)
        {
            if ( state[j] == 3 ) 
                stateduplicate = true;
        }

        int unRegist = 0;
        for (int j=1; j<=9; j++)
        {
            if (state[j] ==0) unRegist++;
        }

        bool noOne = true;
        for (int j=1; j<=9; j++)
        {
            if ( state[j] == 2 || state[j] ==0 ) noOne = false;
        }

        for (int j=1; j<=9; j++)
        {
            if ( state[j] == 0 );
        }

        bool duplicate = false;
        int already = -1;

        for (int j=1; j<=9; j++)
        {
            if ( already == -1 && state[j] == 2 ) already = j;
            else if( already > 0 && state[j] == 2) duplicate = true;
        }

        bool allDead =true;
        for (int j=1; j<=9; j++) 
        {
            if ( state[j] != 1) allDead=false;
        } 

        u[i] ^= 1;

        if ( duplicate || noOne || stateduplicate  ) 
        {
            continue;
        }
        else if ( already == -1 && unRegist >= 2 ) continue;
        else 
        {
            if ( already == -1) 
            {
                for (int j=1; j<=9; j++)
                {
                    if  (state[j] == 0) 
                    {
                        cout << j <<"\n";
                        return 0;
                    }
                }
            }
            else cout << already << " " << i <<"\n";
            return 0;
        }
    }
    cout << "-1\n";
}
