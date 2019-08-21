#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5 + 100;
int l[N], r[N];
 
int main() {
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	int it = 0;
	memset(l, -1, sizeof l);
	memset(r, -1, sizeof r);
	for (int is = 0; is < n; ++is) {
		if (it < m && t[it] == s[is]) {
			l[it] = is;
			++it;
		}
	}
	it = m - 1;
	for (int is = n - 1; is >= 0; --is) {
		if (it >= 0 && t[it] == s[is]) {
			r[it] = is;
			--it;
		}
	}
	int ans = max(n - 1 - l[m - 1], r[0]);
	for (int i = 0; i < m - 1; ++i) {
        ans = max(ans, r[i + 1] - l[i] - 1);
	}
	cout << ans;
}