#include <stdio.h>

int facto(int a){
	if ( a==0) return 1;
	return a*facto(a-1);
}

int main(){
	int n; scanf("%d", &n);
	printf("%d\n", facto(n));
}

