#include <stdio.h>

long long a[1000001], b[1000001];

int main(){
	int n, m, k ; scanf("%d %d %d", &n, &m, &k);

	for (int i=1; i<=n; i++){
		scanf("%lld", &a[i]);
		b[i]=a[i];
		b[i]+=b[i-1];
	}

	while(m || k){
		int tmp, f, t;
		scanf("%d", &tmp);

		if ( tmp==1 ){
			m--;
			scanf("%d %d", &f, &t);
			int diff = a[f]-t; 
			a[f]=t;

			for (int i=f; i<=n; i++) b[i]-=diff;
		}
		else{
			k--;
			scanf("%d %d", &f, &t);
			printf("%lld\n", b[t]-b[f-1]);
		}
	}
}
