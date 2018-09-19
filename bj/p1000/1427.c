#include <stdio.h>

int a[10];
int main(){
	int n; scanf("%d", &n);
	while(n){
		a[n%10]++; n/=10;
	}
	for (int i=9; i>=0; i--){
		while (a[i]--) printf("%d",i);
	}
	printf("\n");
}
