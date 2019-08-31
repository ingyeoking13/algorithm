#include <iostream>

using namespace std;

int a[100];
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >>n;

    for(int i=0; i<n;i++) cin>>a[i];

    int cost= 1e9;
    for (int i=0; i<n; i++)
    {
        int cur = a[i];
        int tmp = 0;
        for (int j=0; j<n; j++)
        {
            int val = a[i] - a[j];
            if ( val < 0) val = -val;
            if ( val%2) tmp++;
        }
        if ( tmp < cost) cost = tmp;
    }
    cout << cost << "\n";
}