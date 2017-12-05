#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf = 10000000;
int a[50], d[50][250001], n;
int go(int k, int diff) {
	if (diff > 250000)  return -inf; 
	if (k == n) {
		if (diff == 0) return 0;
		else return -inf; 
	}
	if (d[k][diff] != -1)  return d[k][diff]; 
	d[k][diff] = go(k+1, diff);
	d[k][diff] = max(d[k][diff], go(k+1, diff+a[k]));
	if (a[k] > diff) {
		d[k][diff] = max(d[k][diff], diff + go(k+1, a[k]-diff));
	} else {
		d[k][diff] = max(d[k][diff], a[k] + go(k+1, diff-a[k]));
	}
	return d[k][diff];
}
int main() {
	cin >> n;
	for (int i=0; i<n; i++)  cin >> a[i]; 
	memset(d,-1,sizeof(d));
	int ans = go(0, 0);
	if (ans == 0) { cout << -1 << '\n'; }
	else { cout << ans << '\n'; }
	return 0;
}
