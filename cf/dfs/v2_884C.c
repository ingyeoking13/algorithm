#include <stdio.h>

int p[100001], v[100001];
int main(){
	int n; scanf("%d",&n );

	long long ans=0, mx1=0, mx2=0;
	for (int i=1; i<=n; i++) scanf("%d", &p[i]);
	for (int i=1; i<=n; i++){
		long long size=1;
		if (v[i]) continue;
		v[i]=1;
		int tmp=p[i];

		while(tmp!=i){
			size++;
			v[tmp]=1;
			tmp=p[tmp];
		}
		if (size>mx1){ mx2=mx1; mx1=size; }
		else if (size>mx2) mx2=size;
		ans+=size*size;
	}
	ans+=mx1*mx2*2;
	printf("%lld\n", ans);
}
