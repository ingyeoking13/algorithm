#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int a[100];
ll cost[100][100];
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m>> k;

    for (int i=0; i<n ;i++)
        cin >> a[i];
    
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin >> cost[i][j];

}