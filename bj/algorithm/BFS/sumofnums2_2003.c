#include <stdio.h>

int add(int a, int b){
	return a+b;
}

int sub(int a, int b){
	return a-b;
}

struct Calc {
	int (*fp[2])(int, int); 
}

int exe(int (*fp)(int, int), int a, int b){
	return fp(a,b);
}

int (*getFunc(struct Calc *c, int index))(int, int){
	return c->fp[index];
}
