#include <bits/stdc++.h>
using ll = long long;
using namespace std;

struct coord {
    int tx, ly, bx, ry;
    coord(int tx, int ly, int bx, int ry) : tx(tx), ly(ly), bx(bx), ry(ry) {}
};

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<string> arr(n);
        for (int i=0; i<n; i++) cin >> arr[i];

        if (arr[0][0]=='1') 
        {
            cout << "-1\n";
            continue;
        }

        queue<coord> ans;
        for (int i= n-1; i>=0; i--) {
            for (int j=m-1; j>=0; j--) {
                if (arr[i][j]=='1') {
                    if (j==0) ans.push(coord(i-1, j, i, j));
                    else {
                        ans.push(coord(i, j-1, i, j));
                    }
                }
            }
        }
        cout << ans.size() <<"\n";
        while(!ans.empty()) {
            coord tmp = ans.front();
            ans.pop();
            cout <<  tmp.tx +1 << " " << tmp.ly + 1 << " " << tmp.bx +1 << " " << tmp.ry + 1 <<"\n";
        }
    }
}