#include <stdio.h>

void useThisProg(){ printf("두 개의 정수를 입력하시면 덧셈결과가 출력됩니다.\n" "입력하세요!\n"); }
int add(int a, int b) { return a+b;}
int readNum(){ int tmp; scanf("%d", &tmp); return tmp; }
void showResult(int a){ printf("정답 : %d\n", a); }

int main(){

	int a, b, ans;
	useThisProg();
	a=readNum(), b=readNum();
	ans = add(a, b);
	showResult(ans);
	&, |, !, 
}

