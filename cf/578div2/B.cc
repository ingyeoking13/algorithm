#include <iostream>
#include <algorithm>

using namespace std;

int a[(int)1e2];
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while(T--)
    {
        int n, k;
        long long m;
        cin >> n >> m >> k;
        bool state = true;

        for (int i=0; i<n; i++)
        {
            cin >> a[i];
        }

        for (int i=0; i<n-1; i++)
        {
            int cur = a[i];
            int next = a[i+1];

            if (next > cur + k)
            {
                int need = next - cur - k;
                if ( need > m )
                {
                    state=false;
                    break;
                }
                else m-= need;
            }
            else 
            {
                int canbe = max(a[i+1] -k, 0);
                int over = a[i] - canbe;
                m += over;
            }
            if (!state ) break;
        }

        if ( state) cout <<"YES\n";
        else cout <<"NO\n";
    }
}