#include <stdio.h>

int main(){

	int T,Case;
	int a,b;
	scanf("%d", &Case);

	for(T=0; T<Case;T++){
		scanf("%d %d", &a, &b);
		printf("Case #%d: %d\n", T+1,a+b);
	}
}

