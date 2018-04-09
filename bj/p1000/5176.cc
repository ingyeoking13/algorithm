#include <stdio.h>
#include <string.h>

int main(){
	int T; scanf("%d", &T);
	while(T--){
		int a[501]; 
		int n, m;  
		memset(a, 0, sizeof(a));
		scanf("%d %d", &n, &m);

		int ans=0;
		for (int i=0; i<n; i++){
			int tmp; scanf("%d", &tmp);
			if ( a[tmp] ) ans++;
			else a[tmp]=1;
		}
		printf("%d\n", ans);
	}
}
