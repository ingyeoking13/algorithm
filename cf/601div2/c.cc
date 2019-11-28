#include <bits/stdc++.h>
using ll = long long;
using namespace std;
 
int cnt[(int)1e5+1];
vector<int> ff[(int)1e5+1];
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin >> n;
    int m = n-2;
 
    for (int i=0; i<m; i++)
    {
        vector<int> tmp;
        int tt;
        for (int j=0; j<3; j++)
        {
            cin >> tt;
            tmp.push_back(tt);
 
            cnt[tt]++;
        }
 
        for (int j=0; j<3; j++)
        {
            for (int k=0; k<3; k++)
            {
                if ( j== k) continue;
                ff[ tmp[j] ].push_back( tmp[k] );
            }
        }
    }
 
    int s =-1, e =-1;
    for (int i=1; i<=n; i++)
    {
        if (s == -1 && cnt[i] ==1) s = i; 
        else if ( s!= -1 && cnt[i] ==1) e = i;
    }
 
    cout << s << " ";
    cnt[s] = 0;
    int prev = s;
 
    int i;
    if ( cnt[ ff[s][0] ] ==2) 
    {
        i = ff[s][0];
        cnt[i] = 0;
    }
    else 
    {
        i = ff[s][1];
        cnt[i]=0;
    }
    cout << i << " ";
 
    while(true)
    {
        int next =-1;
 
        for (int j : ff[i])
        {
            if ( cnt[ j ]  == 3  )
            {
                bool find = false;
                for (int k : ff[prev])
                {
                    if ( k == j) find = true;
                }
 
                if  (find)
                {
                    next = j;
                    cnt[next] = 0;
                    prev = i;
                    break;
                }
            }
        }
        if ( next > 0 ) 
        {
            cout << (i = next) << " ";
        }
        else break;
    }
 
    for (int j : ff[i] )
    {
        if ( cnt[j] == 2 )
        {
            cout << j << " ";
            cnt[j] =0;
            for (int k : ff[j])
            {
                if ( cnt[k] == 1) 
                {
                    cout << k << "\n";
                    cnt[k] =0;
                    break;
                }
            }
        }
    }
}