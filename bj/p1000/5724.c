#include <stdio.h>


int main(){
	while(1){
		int n; scanf("%d", &n);
		if(!n) break;

		int ans=0;
		for (int i=1; i<=n; i++){
			ans+=i*i;
		}
		printf("%d\n",ans);
	}
}
