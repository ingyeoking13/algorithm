#include <stdio.h>

int fibo[45]={0, 1};
int f(int n){
	if (n<=1)
		return n;
	else{
		if(fibo[n]) return fibo[n];
		else return fibo[n]=f(n-1)+f(n-2);
	}
}
int main(){

	int n;
	scanf("%d", &n);

//	for(int i=2; i<=n;i++){
//		fibo[i]=fibo[i-1]+fibo[i-2];
//	}
	f(n);
	printf("%d\n", fibo[n]);
	return 0;
}
