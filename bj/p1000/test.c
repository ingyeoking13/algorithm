#include <stdio.h>

void printF(int a){
	printf("------%d\n", a);
}

int main(){
	int data=printF;
	((void(*)(int))data)(10);
}
