#include <iostream>
<<<<<<< HEAD

using namespace std;
=======
#include <string.h>

using namespace std;
int a[(int)1e3];
bool v[(int)1e3];

int go(int idx)
{
    v[idx] = true;
    int ret = 1;

    if ( v[a[idx]] == false) ret += go (a[idx]);
    return ret;
}
>>>>>>> origin/master
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
<<<<<<< HEAD
=======

    int n;
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
        a[i]--;
    }

    int ans = -1, mx = 0;
    for  (int i=0; i<n; i++)
    {
        memset(v, 0, sizeof(v));
        int val = go(i);
        if ( mx < val) ans =i, mx = val;
    }
    cout << ans +1 <<"\n";
>>>>>>> origin/master
}