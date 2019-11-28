#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int a[(int)2e5+1];
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n[3];
    cin >> n[0] >> n[1] >> n[2];

    for (int i=0; i<3; i++)
    {
        for (int j=0; j<n[i]; j++)
        {
            int tmp;
            cin >> tmp;
            a[tmp] = i;
        }
    }

    int nn = n[0] + n[1] + n[2];
    int cnt[3] = {0, 0, 0};

    for (int i=0; i<nn; i++)
    {
        


    }

}