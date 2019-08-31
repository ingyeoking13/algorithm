#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int a[(int)2e5];
vector<int> j[(int)2e5+1];
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i=0; i<n; i++) cin >> a[i];

    for (int i=0; i<n; i++)
    {
        int j;
        for ( j=0; a[i]; j++) v[a[i]].push_back(j);
        v[0].push_back(j);
    }

}

