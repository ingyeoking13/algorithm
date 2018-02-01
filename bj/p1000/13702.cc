#include <cstdio>

int a[10000];
int main(){
	int n, k; scanf("%d %d", &n, &k);

	int r=0, l=0;
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
		if (r<a[i]) r=a[i];
	}

	int max=0;
	while (l<=r){
		int m= (l+r)/2;
		int cnt=0;
		for (int i=0; i<n; i++){
			int now=a[i];
			while(now>=m) {now-=m; cnt++; }
		}
		if ( cnt >= k ){
			l = m+1;
			if ( max <= m ) max =m;
		}
		else r = m-1;
	}
	printf("%d\n", max);
}
