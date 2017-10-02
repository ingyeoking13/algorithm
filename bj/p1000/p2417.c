#include <stdio.h>
#include <math.h>

int main(){
	unsigned long long int n, i;
	scanf("%llu", &n);
	for (i=0; i*i<n; i++);

	printf("%llu\n", i);
}
