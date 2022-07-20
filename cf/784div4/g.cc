#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >>t;
    while(t--){
        int row, col;
        cin >> row >> col;
        vector<string> mm(row);
        for (int i =0; i<row; i++) cin >> mm[i];

        for (int i=row-1; i>=0;i--) {
            for (int j=0; j<col; j++) {
                if (mm[i][j] != '*') continue;
                int k = i+1;
                while(k<row && mm[k][j] =='.') k++;
                mm[i][j] = '.';
                mm[k-1][j] = '*';
            }
        }
        for (int i=0; i<row; i++) cout << mm[i] <<"\n";
    }
}