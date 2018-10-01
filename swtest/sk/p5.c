#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
	int data[100], top;
}stack;
typedef struct queue{
	stack* s1;
	stack* s2;
}queue;

queue* init(){
	queue* q=(queue *)malloc(sizeof(queue));
	q->s1=(stack *)malloc(sizeof(stack));
	q->s2=(stack *)malloc(sizeof(stack));
	q->s1->top=0; q->s2->top=0;
	return q;
}

void push(stack* s, int d){ s->data[(s->top)++]=d; }
void enque(queue* q, int d){ push(q->s1, d); }
int pop(stack* s){ return s->data[--(s->top)]; }

int deque(queue* q){
	int x;
	if (q->s1->top<=0 && q->s2->top<=0){ return 0xFFFFFFF; }
	if (q->s2->top == 0){
		while (q->s1->top > 0){
			x= pop(q->s1);
			push(q->s2, x);
		}
	}
	x= pop(q->s2);
 	return x;
}

int main(){
	queue* que=init();
	for (int i=1; i<=10; i++){ enque(que, i); }
	for (int i=1; i<=20; i++){ printf("%d\n", deque(que)); }
}
