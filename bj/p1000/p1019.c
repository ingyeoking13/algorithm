#include <stdio.h>

long long a[10];
void cnt(int num){
	while(num){
		a[num%10]++;
		num/=10;
	}
}

int main(){
	int n;
	scanf("%d", &n);

	for (int i=1; i<=n; i++) cnt(i); 
	for (int i=0; i<10; i++) printf("%lld ", a[i]);
	printf("\n");
}
