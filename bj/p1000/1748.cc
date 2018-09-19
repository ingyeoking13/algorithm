#include <bits/stdc++.h>

int len(int now){
	int ret=0;
	while(now){
		now/=10;
		ret++;
	}
	return ret;
}

int main(){
	int n; scanf("%d", &n);
	long long ans=0;
	for (int i=1; i<=n; i++){
		ans+=len(i);
	}
	printf("%lld\n", ans);
}
