#include <iostream>

using namespace std;

int a[(int)150001];
int l[(int)150001], r[(int)150001];
bool b[(int)150002];
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i =0; i<n; i++ )
    {
        int tmp;
        cin >> tmp;
        b[tmp] = true;
        a[tmp]++;
    }

    int left = 1; 
    for (int i=1; i<=150000; i++)
    {
        if ( a[i])
        {
            if (left == 0) left = i;
            l[i] = left;
        }
        else left = 0;
    }

    int right =150000;
    for (int i=150000; i>0; i--)
    {
        if (a[i])
        {
            if (right == 0) right = i;
            r[i] =right;
        }
        else right = 0;
    }

    for (int i=1; i<=150000; i++)
    {
        if ( a[i] >=2)
        {
            if (b[ l[i]-1 ] || l[i] -1 == 0);
            else 
            {
                b[l[i]-1] =true;
                a[i]--;
            }

            if ( a[i] >=2)
            {
                b[r[i]+1] = true;
                a[i]--;
            }
        }
    }

    int ans =0;
    for (int i=1; i<=150001; i++)
    {
        if (b[i]) ans++;
    }
    cout << ans<<"\n";

}