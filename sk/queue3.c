#include <stdio.h>
#include <stdlib.h>

typedef struct node{ int data; struct node* next; }node;
typedef struct{ node* front; node* rear; }queue; 

queue* init(){
	queue* q=(queue *)malloc(sizeof(queue));
	q->front=q->rear=0;
	return q;
}

void push(queue* q, int d){
	node* n= (node *)malloc(sizeof(node));
	n->data=d; n->next=0;
	if (!q->front){
		q->front=q->rear=n; return;
	}
	q->rear->next=n;
	q->rear=n;
}

int pop(queue* q){
	if (!q->front) return 0XFFFFFFF;
	int ret=q->front->data;
	q->front=q->front->next;
	if(!q->front) q->rear=0;
	return ret;
}

queue* sort(queue* q){
	int chk, t=0;
	node* end=0;
	node* now;
	do{
		chk=0;
		now=q->front;
		while(now->next != end){
			if(now->data > now->next->data){
			  int tmp=now->data;
				now->data=now->next->data;
				now->next->data=tmp;
				chk=1; 
			}
			now=now->next;
		}
		end=now;
	} while(chk);
	return q;
}

void printr(queue* q){ printf("%d\n", q->rear->data); }

int main(){
	queue* que=init();
	for (int i=10; i>0; i--){
		push(que, i);
		printr(que);
	}

	que=sort(que);
	 
	for (int i=0; i<15; i++){
		printf("%d \n", pop(que));
	}
}


