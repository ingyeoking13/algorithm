#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element;
typedef struct stackNode {
	element data;
	struct stackNode *link;
} stackNode;
stackNode *top;

void push(element item) {
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
	temp->data = item;
	temp->link = top;
	top = temp;
}

element pop() {
	element item;
	stackNode *temp = top;
	if (top == NULL) return 0; 

	item = temp->data;
	top = temp->link;
	free(temp);
	return item;
}

int testPair(char *exp) {
	char symbol, open_pair;
	int i, length = strlen(exp);
	top = NULL;

	for (i = 0; i < length; i++) {
		symbol = exp[i];
		switch (symbol) {
			case '(':
			case '[':
			case '{':
			//peek을 이용한 순서 검사 추가
			push(symbol); break;
			case ')':
			case ']':
			case '}':
			if (top == NULL) return 0;
			else {
				open_pair = pop();
				if ((open_pair == '(' && symbol != ')') ||
						(open_pair == '[' && symbol != ']') ||
						(open_pair == '{' && symbol != '}')	)
				return 0;
				else break;
			}
		}
	}
	if (top == NULL) return 1;
	else return 0;
}

void main(void) {
	char *express = "{(A+B)-3}*5+[{cos(x+y)+7}-1]*4 ";
	printf("%s", express);

	if (testPair(express))  printf("\n\n 수식의 괄호가 맞게 사용되었습니다.\n");
	else printf("\n\n 수식의 괄호가 틀렸습니다!\n");
}
