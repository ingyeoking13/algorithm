/*

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char s[10000]; //대충 stack size 10000...
int top =-1;
int oper(char c){ return c =='+' || c=='-' || c=='*' || c=='/'; }

char* infix_to_postfix(char* str){
	int len = strlen(str); 
	char* ret = (char*)malloc(len); // 동적할당 !
	int retlen=0;

	for (int i=0; i<len; i++){ // S문자열 을 순회!
		if (oper(str[i])) s[++top] = str[i]; //S[i] 가 연산자일경우
		else if(str[i] == '(') s[++top] = str[i]; //S[i] 가 괄호일경우
		else if(str[i] == ')'){ // S[i]가 닫는 괄호일경우!
			while(s[top]!='('){ //여는 괄호일 때까지 stack에서 기호빼온다
				ret[retlen++]=s[top--]; 
			}
			top--; //그리고 한번더 top을뺀다 (이건 여는괄호이다)
		}
		else {
			ret[retlen++]=str[i]; //숫자나 뭐 다른 기호일경우 뺀다
		}
	}
	while(top>=0) ret[retlen++]=s[top--];
	return ret;
}

int evalPostfix(char* str){
	int len = strlen(str);

	for (int i=0; i<len; i++){
		if (oper(str[i])){
			int a = s[top--];
			int b = s[top--];
			if (str[i] == '-') s[++top] = b-a;
			else if (str[i]=='+') s[++top] =b+a;
			else if (str[i]=='*') s[++top] =b*a;
			else if (str[i]=='/') s[++top] =b/a;
		}
		else s[++top]=str[i]-'0';
	}

	return s[top--];
}

int main(){ // from the script
	char* infix = "(9-((4/2)+1))*((5*2)-1)";
	printf("중위 표기식: %s\n", infix);

	char* postfix = infix_to_postfix(infix);
	printf("후위 표기식: %s\n", postfix);
	
	int result = evalPostfix(postfix);
	printf("연산 결과 : %d\n", result);
	free(postfix);

	getchar();
}
