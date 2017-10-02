#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack{
	int top;
	char data[600000];
}stack;

stack* init(){
	stack* s=(stack *)malloc(sizeof(stack));
	s->top=0;
	return s;
} 
int empty(stack* s){ return s->top==0; }
char pop(stack* s){ return s->data[--(s->top)]; } 
void push(stack* s, char d){ s->data[s->top++]=d; }

char in[600000];
int main(){
	stack* s1=init();
	stack* s2=init();
	scanf("%s", in);
	int T;
	scanf("%d", &T);
	int len=strlen(in);
	for(int i=0; i<len; i++) push(s1, in[i]);

	while(T--){
		scanf("%s", in);
		if (in[0]=='L'){
			if(!empty(s1)) push(s2 ,pop(s1));
		}
		else if(in[0]=='D'){
			if(!empty(s2)) push(s1, pop(s2));
		}
		else if(in[0]=='B'){
			if(!empty(s1)) pop(s1);
		}
		else if(in[0]=='P'){
			scanf("%s", in);
			push(s1, in[0]);
		}
	}
	while(!empty(s2)) push(s1, pop(s2));
	while(!empty(s1)) push(s2, pop(s1));
	while(!empty(s2)) printf("%c", pop(s2));
	printf("\n");
}
