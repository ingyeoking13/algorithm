#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	vector<int> v;
	int n, k; scanf("%d %d", &n, &k);
	for (int i=0; i<n; i++){
		int tmp;
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());

	int l =1, r=v[n-1];
	int ans=-1;
	while(l<=r){
		auto i = upper_bound(v.begin(), v.end(), (l+r)/2);
		int cnt = i-v.begin();
		if (cnt ==k) {
			ans= (l+r)/2;
			break;
		}
		else if ( cnt > k) r = (l+r)/2-1;
		else l = (l+r)/2+1;
	}
	printf("%d\n", ans);

}
