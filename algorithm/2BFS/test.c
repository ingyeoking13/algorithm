#include <stdio.h>

int add(int a, int b, int c){
	return a+b+c;
}
int mul(int a, int b){
	return a*b;
}

struct Calc {
	int (*fp)();
};

int exe(int (*fp)()){
	printf("%d\n", fp(20, 50));
}

int (*getFunc(char a,char b))(){
	return add;
}

typedef int (*FP)(int, int);

FP getFunc2(){
	return mul;
}


int main(){

	struct Calc S;
	S.fp = add;
	printf("%d\n", S.fp(2, 5, 1));
	S.fp = mul;
	printf("%d\n", S.fp(9, 2));

	int (*fp)();
	fp=add;
	printf("%d\n", fp(2,5,1));
	fp=mul;
	printf("%d\n", fp(2,5));

	exe(add);
	exe(mul);

	printf("%d\n", getFunc(2, 5)(5,5, 5));
	FP fp2;
	FP fp3[10];



}
