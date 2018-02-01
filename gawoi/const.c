#include <stdio.h>

int main(){
	int num=20;
	const int* const ptr = &num;
	//*ptr = 30;
	num=40;
	printf("%d\n", *ptr);
}
