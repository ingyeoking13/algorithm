#include <stdio.h>

int a[16] = {1, 2, 3, 5, 6, 7, 8, 10, 
	12, 13, 15, 16, 18, 19, 20, 22};

int main(){
	int l=0, r=15, item=19;

	while (l<r){
		int m=(l+r)/2;
		if (item > a[m]) l=m+1;
		else r=m;
	}
	if (a[l]==item) printf("%d\n", l);
	else printf("NOT FOUND\n");
}

