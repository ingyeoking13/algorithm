#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
int d[(int)1e6+1];

int go(int cur)
{
    if ( cur <= 1 ) return 0;
    if ( d[cur] >= 0)  return d[cur];

    d[cur] = 1e9;
    if ( cur%2 == 0 ) d[cur] = go(cur/2)+1;
    if ( cur%3 == 0 ) d[cur] = min( go(cur/3) +1, d[cur] );
    d[cur] = min(go(cur-1)+1, d[cur]);
    return d[cur];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(d, -1, sizeof(d));

    int n; 
    cin >> n;

    cout << go(n) << "\n";
}