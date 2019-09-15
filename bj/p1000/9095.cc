#include <iostream>
#include <string.h>

using namespace std;
int d[(int)1e6+1];
int cnt = 0 ;

int go(int cur)
{
    if ( cur < 0 ) return 0;
    if ( cur == 0) 
    {
        cnt++;
        return 1;
    }

    if ( d[cur] >= 0 ) 
    {
        cnt++;
        return d[cur];
    }
    int &ret = d[cur];
    ret = 0;

    ret += go(cur-1);
    ret += go(cur-2);
    ret += go(cur-3);

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while(T--)
    {
        memset(d, -1, sizeof(d));
        cnt =0 ;
        int n ;
        cin >> n;
        //cout << go(n) << "\n";
        go(n);
        cout << cnt <<"\n" ;
    }
}