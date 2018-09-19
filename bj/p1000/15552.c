#include <stdio.h>

int main(int a,int b,int T){
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &a, &b);
		printf("%d\n", a+b);
	}
}
