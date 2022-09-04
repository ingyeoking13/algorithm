#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int main() {
	int n;
    cin >> n;

    vector<int> v(8001, 0);
    for (int i =0; i<n; i++) {
        int temp;
        cin >> temp;
        v[temp+4000] += 1;
    }

    int sum = 0;
    for (int i=0; i<=8000; i++) {
        sum += (i - 4000)* v[i];
    }
    cout << (int)round(double(sum) / n ) << "\n";

    int mid = n/2  + (n%2?1:0); 
    for (int i=0; i<=8000; i++) {
        mid -= v[i];
        if (mid <=0){
            cout << (i - 4000) <<"\n";
            break;
        }
    }

    int d = 0;
    for (int i=0; i<=8000; i++) {
        if (d < v[i]) {
            d = v[i];
        }
    }

    int non = 0;
    int cnt = 2;
    for (int i=0; i<=8000; i++) {
        if (d == v[i]) {
            non = i - 4000;
            cnt--;
            if (cnt == 0) {
                cout << i - 4000 << "\n";
                break;
            }
        }
    }

    if (cnt == 1) {
        cout << non << "\n";
    }

    int mx = 8000;
    int mn = 0;
    while (mx >= 0){
        if(v[mx]>0) break;
        mx--;
    }

    while (mn <= 8000) {
        if (v[mn]>0) break;
        mn++;
    }
    cout << mx - mn <<"\n";
}