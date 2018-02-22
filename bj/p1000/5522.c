#include <stdio.h>

int main(){
	int ans=0;
	for (int i=0 ;i<5; i++){
		int n; scanf("%d", &n);
		ans+=n;
	}
	printf("%d\n",ans);
}
