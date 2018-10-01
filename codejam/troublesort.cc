#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int T; scanf("%d", &T);
	for (int t=1; t<=T; t++){
		int n; scanf("%d", &n);

		vector<int> a,b;

		for (int i=0; i<n; i++){
			int tmp;scanf("%d", &tmp);
			if ( i%2) a.push_back(tmp);
			else b.push_back(tmp);
		}

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		vector<int> c;

		int cnta=0, cntb=0;
		for (int i=0; i<n; i++){
			if (i%2) c.push_back(a[cnta++]);
			else c.push_back(b[cntb++]);
		}

		int ans=-1;
		for (int i=0; i<n-1; i++){
			if ( c[i] > c[i+1])  {ans=i; break;}
		}
		if ( ans>=0) printf("Case #%d: %d\n", t, ans);
		else printf("Case #%d: OK\n", t);
	}

}
