/*
	 infix 는 우리가 평소에 쓰는 수식을 쓰는 한 방식이다.
	 infix 에서 postfix 로 바꾸면 다음과 같다.
	 (A+B)*C -> AB+C*
	 변환 방식은 다음과 같은 규칙을 따르면 된다.

	 for (int i=0; i<len; i++){ ... 로 시작한다.
	 문자열을 차례로 탐색하는데 일단 다 stack에 넣는다

	 stack (.A.
	 stack (.A.+.
	 stack (.A.+.B.

	 여기서 이제 다음 character가 ')' 인데 
	 괄호연산자는 연산의 우선순위를 정하므로, 
	 여기서 한번 '(' 까지의 stack 자료를 다 뱉어냄으로써
	 postfix에서의 연산 우선순위를 지킬 수있다. 
	 괄호 뒤의 수식은 괄호 앞의 연산보다 낮은걸 생각하자.

	 ret B.+.A

	 그리고 계속해서 문자열 순회를 하며, stack에 넣는다
	 stack *.
	 stack *.C.

	 이제 문자열 순회가 끝났다.
	 그렇다면 연산이 따로 없으므로, stack에 있는걸 다 뱉어내면된다.
	 ret B.+.A.*.C.

	 지금 따라온 것은 정확하게 수행하면 항상 valid 한 infix를 valid한 postfix 수식으로 바군다.
	 이런 순차적인 행위를 알고리즘이라 하며, infix -> postfix 로 바꾸는 알고리즘이다.

	 괄호가 연산의 우선순위를 결정하고 그게 postfix로 변환하는데 중요한 역할을 하는것을 
	 다시 유념하자, 괄호가 나오면 해당 여는 괄호까지 모든 stack을 뱉어낸다.

	 하지만 연산의 우선순위는 +, *, -, / 사이에도 존재한다.
	 만약 당신이 임의의 연산자를 받았다고 하자. 만약 그 연산자 뒤로 오는것이 앞에 오는것보다
	 우선순위 가 낮다면 그 앞에것들의 스택을 뱉어내야한다.

	 어떤 연산자가 주어지면 그 연산이 우선순위가 낮은 경우가 제일 많은 연산자는 무엇일까?
	 바로 '+', '-' 이다.
	 A+B-C이면, AB+C- 가 되어야한다. 왜냐하면 - 연산자는 +보다 우선순위가 낮은경우이다.
	 ABC-+ 와 는 다르다는것을 명심하자.
	 따라서, '+', '-' 연산자를 받으면 stack이 연산자일 때까지 다 뱉어내면된다. (stack엔 연산자+괄호가있음)

	 연산자 '*', '/'는 그 뒤의 식이 '*', '/' 인 경우를 제외하고는 우선순위가높다
	 A+B*C이면, ABC*+가 되어야한다. 왜냐하면 *는 +보다 우선순위가 높다! 그래서 +는 stack에 계속머무른다.
	 하지만 A/B*C이면, AB/C*가 되어야한다
	 따라서 '*', '/' 연산자를 받으면 stack이 '*', '/'일 때만 뱉어내면된다.

	 조금 더 전문적으로 기술하면, 사실 모든 수식은 tree형태로 그려질 수 있다. 
	 (이미 수업시간에 들었을 수도 있지만...)

	 (A+B)*C 는 다음과같다.

	    *
	 	+   C
	 A B

	 A+B*C 는 다음과같다.

	   +
	 A   *
      B C

	 postfix는 이 tree를 traverse(돌아다니는)하는 한 방법에 불과하다.
	 
	 왼쪽부터 간뒤 바닥을 치면 부모노드의 그 우측 자식한테로간다. 그뒤 부모에게 간다.
	 이것을 반복하는 것이다.

	 그리고 이 tree 탐색을 stack을 이용해서 할 수 있는것이다. 그 성격이 같은 재귀로해도된다. 

	 ps. 만약 당신이 어떠한 수에도 잘 동작하려고 한다면, 조금 더 복잡한 방법을 따라야한다.
	 왜냐하면 char 형 stack은 오직 1byte만 담을수 있기 때문이다.
	 만약 당신이 여러 바이트의 숫자를 다루려면 (즉, 2자리 이상의...)
	 적절한 크기의 char형 tmp배열을 선언한뒤 일단 숫자가 오면 그걸 다 저장해놓고, 
	 다른 연산자가 오면 그걸 거꾸로 stack에 넣어주면된다.

	 구현하려고했는데 어떤 코어한 동작원리를 놓칠까봐 여기까지했습니다.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int s[10000], top =-1; //대충 stack size 10000...
int oper(char c){ return c =='+' || c=='-' || c=='*' || c=='/'; }

char* infix_to_postfix(char* str){
	int len = strlen(str); 
	char* ret = (char*)malloc(len+1); // 동적할당 !
	int retlen=0;

	for (int i=0; i<len; i++){ // S문자열 을 순회!
		int chk=0;
		if (oper(str[i])) {
			if(str[i]=='*' || str[i]=='/') { // *, / 인경우
				while(top>=0 && (s[top]=='*' || s[top]=='/')){ //자신의 앞이 '*', '/'일경우 뱉어낸다
					ret[retlen++] = s[top--];
				}
				s[++top] = str[i]; //그리고 해당녀석은 stack에 들어감
			}
			else{  // +, - 인경우
				while(top>=0 && oper(s[top])){// s[i] == '+', s[i] =='-' 이면, 앞의 연산자일 때까지 다 뱉어낸다.
					ret[retlen++] = s[top--]; 
				}
				s[++top] =str[i]; // 그리고 해당녀석은stack에 들어감 
			}
		}
		else if(str[i] == '(') s[++top] = str[i]; //S[i] 가 괄호일경우
		else if(str[i] == ')'){ // S[i]가 닫는 괄호일경우!
			while(s[top]!='('){ //여는 괄호일 때까지 stack에서 기호빼온다
				ret[retlen++]=s[top--]; 
			}
			top--; //그리고 한번더 top을뺀다 (이건 여는괄호이다)
		}
		else ret[retlen++]=str[i]; //숫자인 경우
	}

	while(top>=0) ret[retlen++]=s[top--];
	ret[retlen++]=0;
	return ret;
}

int evalPostfix(char* str){
	int len = strlen(str);

	for (int i=0; i<len; i++){
		if (oper(str[i])){
			int a=s[top--];
			int b=s[top--];
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
//	char* infix = "(9-((4/2)+1))*((5*2)-1)";
//	char* infix = "9-3*2+5";
	char* infix = "9*9/1*1*5*3/3";
	printf("중위 표기식: %s\n", infix);

	char* postfix = infix_to_postfix(infix);
	printf("후위 표기식: %s\n", postfix);
	
	int result = evalPostfix(postfix);
	printf("연산 결과 : %d\n", result);
	free(postfix);

	getchar();
}
