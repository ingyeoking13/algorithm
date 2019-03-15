#include <stdio.h>
int main(){
	long long n; scanf("%lld", &n);
	

	if ((n+1)%2==0){
		printf("%lld", (n+1)/2L);
	}else if(n==0){
		printf("0");
	}else{
		printf("%lld", n+1);
	}
	printf("\n");


}

