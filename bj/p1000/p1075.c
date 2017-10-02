#include <stdio.h>

int main(){

	int n, f, i;
	scanf("%d %d", &n, &f);
	n/=100;
	n*=100;

	for (i=n;;i++){
		if (i%f==0) break;
	}
	n=i%100;
	if (n/10) printf("%d\n", n);
	else printf("%d%d\n", 0, n);
}
