#include <stdio.h>

int main(){

	int n, m, set=10000, each=10000, tmp;
	scanf("%d %d", &n, &m);
	for (int i=0; i<m; i++){ 
		scanf("%d", &tmp); if (set>tmp) set=tmp;
		scanf("%d", &tmp); if (each>tmp) each=tmp;
	}

	int ans;
	if (set>=each*(6<n?6:n)) ans=each*n; 
	else{ 
		ans=set*((6<n?n:6)/6)+each*((6<n?n:0)%6); 
	}

	printf("%d\n", ans);
}
