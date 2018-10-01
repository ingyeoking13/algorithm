#include <stdio.h>

long long d[100]={1, 1, 1};
int main(){

	for (int i=3; i<100; i++){
		d[i]=d[i-1]+d[i-2]+1;
	}

	for (int i=1; i<100; i++){
		printf("%d %lld\n", i,d[i]);
	}
}



