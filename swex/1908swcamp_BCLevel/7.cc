#include <iostream>

using namespace std;
int main()
{
    int T;
    cin >> T;
    for (int tc=1; tc<=T; tc++)
    {
        int ans =0;
        int cur = 0;
        int n;
        cin >> n;

        for (int i=0; i<n; i++)
        {
            int tmp;
            cin >> tmp;
            cur += tmp;

            if ( ans < cur ) ans=cur;
            if ( cur < 0 ) cur =0;
        }

        cout << "#" << tc << " " << ans <<"\n";
    }
}