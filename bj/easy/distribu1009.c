#include <stdio.h>

int main(){

	int T,a,b;
	scanf("%d", &T);

	while(T--){
		int ans[4]={0,0,0,0};
		scanf("%d %d", &a, &b);
		ans[0]= a;
		ans[1]= a*a%10;
		ans[2]= a*a*a%10;
		ans[3]= a*a*a*a%10;
		if(!ans[b%4]) printf("10\n");
		else printf("%d\n", ans[b%4]);
	}
}
