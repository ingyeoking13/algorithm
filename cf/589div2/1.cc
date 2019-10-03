#include <iostream>

using namespace std;

int cnt[10];
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int l, r;
    cin >> l >> r;


    int ans = -1;
    for (int i=l; i<=r; i++)
    {
        for (int j=0; j<10; j++) cnt[j] = 0;

        int tmp = i;
        bool fine = true;

        while (tmp)
        {
            cnt[tmp%10]++;
            if ( cnt[tmp%10] >= 2) 
            {
                fine = false;
                break;
            }
            tmp/=10;
        }
        if ( fine ) 
        {
            ans = i;
            break;
        }
    }
    cout << ans <<"\n";
}