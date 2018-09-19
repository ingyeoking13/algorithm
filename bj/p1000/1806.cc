#include <cstdio>

int a[100000], sum[100000];
int main(){
	int n, s; scanf("%d %d", &n, &s);
	for (int i=0; i<n; i++) scanf("%d", &a[i]);
	for (int i=0; i<n; i++) sum[i]=sum[i-1]+a[i];

	int l=0, r=0, ans=100001;
	while(r<n){
		int now = sum[r] - sum[l-1];
		if (now < s) r++;
		else if (now >= s) {
			if ( ans > r-l+1 ) ans = r-l+1;
			l++;
		}
		if ( l>r )  r++;
	}
	printf("%d\n", ans==100001?0:ans);
}
