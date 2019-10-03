#include <iostream>
#include <string.h>
using namespace std;

long long d[1001], d2[1001];
int go (int now)
{
    if (d[now]>=0) return d[now];
    d[now] =0;

    int ret = 0;
    for (int mid=1; mid<= now; mid++)
    {
        int mod = (now-mid)%2;
        if ( mod %2 == 0 ) 
            ret += go((now-mid)/2);
    }

    if ( now%2 ==0 )
        ret += go(now/2);

    return d[now] = ret;//+1;
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    memset(d, -1, sizeof(d));
    d[0]=1;
    d2[0]= 0;

    for (int i=1000; i>=1; i--)
    {
        go(i);
        //cout << i << " " << d[i] << " \n";
    }
    int T;
    cin >> T;
    while (T-- )
    {
        int n;
        cin >> n;
        cout << d[n] <<"\n";
    }
}