// 항상 더 짧은 코드가 없을 지 생각해봅시다.
#include <stdio.h>

char get_symbol(char s[]){ 
	// static variable 은 해당 함수 내에서만 사용가능한 전역변수 이다.
	// 단 한번만 초기화 되며 다음에 이 함수를 호출하여도
	// 변경 된 값 그대로 유지할 수 있다.
	static int pos=0; 
	char ret=s[pos++];  
	while(ret==' ') ret=s[pos++];
	return ret; // 만약 문자열 맨 마지막이면? ret == '\0' == 0 (ascii)
}

void display_symbols(char s[]){
	// so simple
	char c;
	while(c = get_symbol(s)) printf("%c", c); // if c =='\0' end while
	printf("\n");
}

//사실 더 작은걸 요구하지만 큰 논리를 짜봤습니다.
//수식을 받을땐 상태라는게 존재합니다.
// state == 0 ,  init state.. state == 1 ,  digit
// state == 2 ,  operator.. state == 3,4  (, )

int ret_state(char c){
	if ( c == ')' ) return 4;
	if ( c == '(' ) return 3;
	if ( c == '*' || c== '+' || c == '/' || c== '-') return 2;
	return 1;
}

int p[5][5] = {{0, 1, 0, 1, 0},//초기상태에서 숫자, 괄호 가능 
               {0, 1, 1, 0, 1},//숫자상태에서 숫자, 연산자, 괄호가능
							 {0, 1, 0, 1, 0},//연산자상태에서 숫자, 괄호가능
							 {0, 1, 0, 1, 1},//여는 괄호에서 숫자, 괄호가능 
							 {0, 0, 1, 1, 1}};//닫는 괄호에서 연산자, 괄호가능

int test_simple_paren(char* expr){
	char s[1000]; //stack MAX size 1000
	int top=0;

	int state=0; // init state 

	char c;
	while(c=get_symbol(expr)){
//		printf("%c\n", c); <--주석 해제 해보세요  
		if ( p[state][ret_state(c)] ){  //가능한 상태이동
			//그렇더라도 괄호 예외처리해주고요
			if (c == '(')  s[top++] = '('; // ( 면 stack 에 쌓음
			else if ( c== ')') {
				if (top==0) return 0;
				if (s[top-1]=='(') top--;
			}
		}
		else return 0; //가능한 상태가 아니면 바로 함수종료

		state=ret_state(c);
	}
	if (top == 0) return 1; 
	else return 0; // 일부 괄호가 남아있다면.... 에러
}

int main(){
	//a, b, c
//	display_symbols("k   imc   hi");

	//d, e
	char* expr = "2+3*5+3+ (3-1)   /2";
	int chk = test_simple_paren(expr);
	if (chk) printf("parentheses are balanced\n");
	else		 printf("parentheses are NOT balanced\n");
	return 0;
}
