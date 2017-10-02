#include <stdio.h>

int main(){

	int n, i, path=0;
	scanf("%d", &n);

	for (i=1;;i++){
		if (n>i*6){
			n-=i*6;
			path++;
		}
		else break;
	}
	printf("%d\n", path+1);
}
