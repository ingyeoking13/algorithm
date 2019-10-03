#include <iostream>

using namespace std;
int a[1000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    for (int i=0; i<n; i++ )
        cin >> a[i];

    int ans =0;
    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
            if ( i!=j && a[i] +a[j] == k ) ans++;
    cout <<ans <<"\n";

}