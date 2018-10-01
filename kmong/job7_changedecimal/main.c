#include <stdio.h>
#include <stdlib.h>

int getInput(int);

typedef struct node{ char val; struct node* next; }Node;
typedef struct{ struct node* top; }Stack;

Stack* Init(){ // stack init
	Stack* s= (Stack*) malloc(sizeof(Stack));
	s->top=0;
	return s;
}

char prec(int n ){ // precalculation for stack push
	if (n >=10) return n-10+'A'; // we can use alphabet for 11~16 base.
	else return n+'0';
}

void push(Stack* s, int n){
	Node* newN = (Node*) malloc(sizeof(Node));
	newN->val = prec(n), newN->next =0;
	if (!s->top){ s->top =newN; return ; }
	newN->next=s->top;
	s->top = newN;
}

void pop(Stack* s){ // stack pop
	Node* now = s->top;
	s->top= s->top->next;
	free(now);
}

char top(Stack* s){ return s->top->val; }  // stack top
int empty(Stack* s){ return s->top==0; } // stack empty

int main(){

	int  n=0;
	Stack* s=Init();
	while(1){ // menu

		printf("1. Insert a decimal number\n");
		printf("2. Convert\n");
		printf("3. Exit\n");
		int ans= getInput(0);

		if ( ans== 1) n= getInput(ans);
		else if (ans==2 ){
			int base = getInput(ans); // we get base
			int tmp=n;

			while(tmp){  // while number modular
				push(s, tmp%base); // we push it 
				tmp/=base;
			}

			while(!empty(s)){  // and then we pop it from the top of stack
				printf("%c", top(s)); // while top exist
				pop(s);
			}
			printf("\n");

		}
		else if (ans==3){ printf("Exit\n"); break; }
		else getInput(ans);
	}
}

int getInput(int op){
	int ret;
	if (op==0){ printf(">> "); scanf("%d", &ret);}
	else if (op==1){ printf("Decimal number: "); scanf("%d", &ret);}
	else if (op==2) { printf("Enter the number system(max 16): ");
		scanf("%d", &ret);
	}
	else printf("no valid option\n"), ret=-1;
	return ret;
}
