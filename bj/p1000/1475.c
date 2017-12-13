#include <stdio.h>

int a[10];
int main(){
	int n; scanf("%d", &n);
	if (n==0) a[n]++;
	while(n){
		a[n%10]++;
		n/=10;
	}
	int tmp=(a[6]+a[9])/2;
	a[6]=a[6]+a[9]-tmp;
	a[9]=tmp;
	int max=0;
	for (int i=0; i<10; i++) max=max<a[i]?a[i]:max;
	printf("%d\n", max);
}
