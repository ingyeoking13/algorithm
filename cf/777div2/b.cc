#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> arr(n);
        vector<vector<bool> > visit(n, vector<bool>(m, false));
        for (int i=0; i<n; i++) cin >> arr[i];

        bool ans = true;
        // solution
        int dx[4] ={1,-1,0,0}, dy[4] ={0,0,-1,1};
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (arr[i][j]=='1' && !visit[i][j]) {
                    int tx = i, ly = j;
                    int bx = i, ry = j;
                    queue<pair<int, int> > q;
                    q.push(make_pair(i, j));
                    visit[i][j] = true;
                    while(!q.empty()) 
                    {
                        pair<int ,int> p = q.front();
                        int x = p.first, y = p.second;
                        q.pop();
                        for (int k=0; k<4; k++) {
                            int nx = x+dx[k], ny = y+dy[k];
                            if (nx < 0 || ny <0 || nx >= n || ny >= m) continue;
                            if (arr[nx][ny] =='0') continue;
                            if (visit[nx][ny]) continue;
                            visit[nx][ny]=true;
                            bx = max(nx, bx), ry = max(ry, ny);
                            tx = min(nx, tx), ly = min(ly, ny);
                            q.push(make_pair(nx,ny));
                        }
                    }
                    // check
                    for (int k=tx; k<=bx; k++) {
                        for (int l=ly; l<=ry; l++) {
                            if (arr[k][l]=='0') ans = false;
                        }
                    }
                }
                if (ans == false) break;
            }
            if (ans == false) break;
        }
        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }
}