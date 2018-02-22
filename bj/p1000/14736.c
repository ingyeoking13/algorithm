#include <stdio.h>

int a[1000], b[1000], c[1000], d[1000], e[1000];
int main(){
	int n, k, al;
	scanf("%d %d %d", &n, &k, &al);
	for (int i=0; i<n; i++){
		scanf("%d %d", &a[i], &b[i]);
	}

	int t=0, ans;
	while(t++>=0){
		for (int i=0; i<n; i++){
			if (d[i]<a[i]) {c[i]+=al; d[i]++; e[i]=b[i];}
			else {
				e[i]--;
				if (!e[i]) d[i]=0;
			}

		}

		ans=0;
		for (int i=0; i<n; i++){
			if (c[i]>=k)  ans=t;
		}
		if (ans) break;
	}
	printf("%d\n", ans);
}
