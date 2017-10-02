#include <stdio.h>
#include <stdlib.h>
#define NOTFOUND 0xffffff

typedef struct node{
	int data;
	struct node* next;
}node;
typedef struct{
	node* front;
	node* rear;
}queue;

queue* c_que(){
	queue* p = (queue*)malloc(sizeof(queue*));
	p->front = p->rear=0;
	return p;
};

void e_que(queue* q, int d){
	node* n = (node*)malloc(sizeof(node));
	n->data=d;
	if (!q->rear) {
		q->front=q->rear=n; return;
	}
	q->rear->next =n;
	q->rear=n;
};

void d_que(queue* q){
	if (!q->front) return ;
	q->front = q->front->next;
	if (q->front==0) q->rear = 0;
	return ;
}
void print(queue* q){ printf("%d ", q->rear->data); }

int main(){
	queue* que= c_que();
	for (int i=0; i<10; i++){
		e_que(que, i);
		print(que);
		printf("\n");
	}
	for (int i=0; i<11; i++){
		d_que(que);
		printf("%d \n", que->front?que->front->data:NOTFOUND);
	}
}
