#include <iostream>
#include <algorithm>
#include <vector>

using ll = long long;
using namespace std;

int a[(int)1e5+1], b[(int)1e5+1];
vector<pair<int,int>> ans;
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i=1; i<=n; i++)
    {
        int tmp;
        cin >> tmp;
        a[i] = a[i-1] + (tmp==1);
        b[i] = b[i-1] + (tmp==2);
    }


    int cnt = 0, cnt2=0;
    for (int t=1; t<=n; t++)
    {
        int st = 1;
        cnt  =0, cnt2=0;
        while(true)
        {
            int l = st, r = n;
            while( l<=r )
            {
                int mid = (l+r)/2;
                if ( a[mid] - a[st-1] >= t ) r = mid -1;
                else l = mid + 1;
            }

            int first = l;
            l = st, r=n;

            while( l<=r )
            {
                int mid = (l+r)/2;
                if ( b[mid] - b[st-1] >= t) r= mid-1;
                else l = mid+1;
            }

            int second = l;

            if ( first > n && second > n )
            {
                break;
            }

            int mn = min( first ,second );
            if ( mn == first ) cnt++;
            else cnt2++;

            if ( mn == n )
            {
                if (((mn == first) &&  cnt>cnt2)||((mn == second) && cnt<cnt2))
                {
                    ans.push_back({ max(cnt, cnt2) , t});
                }
                break;
            }
            st = mn +1;
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() <<"\n";

    for (pair<int, int> p : ans )
        cout << p.first << " " << p.second << "\n";
}