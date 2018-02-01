#include <stdio.h>

void tsum(int* a, int len, int *psum);
int main(){
	int a[5] = {1,2,3,4,5};
	int len = 5;
	int sum = 0;

	tsum(a, len, &sum);
	printf("%d\n", sum);
}

void tsum(int* a, int len, int *psum){
	for (int i=0; i<len; i++){
		*psum += *(a+i);
	}
}
