#include <stdio.h>

int main(){
	int T; scanf("%d", &T);
	while(T--){
		int n; scanf("%d", &n);
		int ans=0, tmp;
		for (int i=0; i<n; i++) {
			scanf("%d", &tmp); 
			ans+=tmp;
		}
		printf("%d\n", ans);
	}
}
