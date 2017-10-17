#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int element;
typedef struct StackNode {
	 element item;
	 struct StackNode *link;
} StackNode;
typedef struct {
	 StackNode *top;
} LinkedStackType;

void init(LinkedStackType *s) { s->top = NULL; }
int is_empty(LinkedStackType *s) { return (s->top == NULL); }

void push(LinkedStackType *s, element item) {
	StackNode *temp = (StackNode*)malloc(sizeof(StackNode));
	temp->item = item;
	temp->link = s->top;
	s->top = temp;
}

element pop(LinkedStackType *s) {
	if(is_empty(s)) {
		fprintf(stderr,"스택이 비어있음\n");
		exit(1);
	}
	else{
		StackNode *temp=s->top;
		element item = temp->item;
		s->top = s->top->link;
		free(temp);
		return item;
	}
}


void display(LinkedStackType* s){
	for (StackNode* now=s->top; now; now=now->link){
		printf("%d ", now->item);
	}
	printf("\n");
}

int get_height(LinkedStackType* s){
	int ret=0;
	for (StackNode* now=s->top; now; now=now->link) ret++;
	return ret;
}

int compare(LinkedStackType* s, LinkedStackType* t){
	int ret=1;
	for(StackNode* ns=s->top,* nt=t->top; ns || nt; ns=ns->link, nt=nt->link){
		if (!ns) ret=0;
		else if (!nt) ret=0;
		else if (ns->item != nt->item) ret=0;
		if (!ret) break;
	}
	return ret;
}

int main(){

	LinkedStackType* s=(LinkedStackType*)malloc(sizeof(LinkedStackType));
	LinkedStackType* t=(LinkedStackType*)malloc(sizeof(LinkedStackType));
	init(s); init(t);
	printf("push items into s 1 from 10 \n");
	for(int i=1; i<=10; i++) {
		push(s, i);
		printf("push data: %d, height: %d\n", i, get_height(s));
	}
	printf("display all items of s: ");
	display(s);

	printf("push items into t 1 from 12 \n");
	for(int i=1; i<=12; i++) {
		push(t, i);
		printf("push data: %d, height: %d\n", i, get_height(s));
	}
	printf("display all items of t: ");
	display(t);

	printf("compare s and t : %d\n", compare(s,t));

	printf("pop all items from s \n");
	for (int i=0; i<10; i++) 
		printf("popped item: %d, height: %d\n" ,pop(s), get_height(s));

	printf("pop all items from t \n");
	for (int i=0; i<15; i++) 
		printf("popped item: %d, height: %d\n" ,pop(t), get_height(t));

}
