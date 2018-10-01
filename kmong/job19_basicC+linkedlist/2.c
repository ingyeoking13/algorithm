#include <stdio.h>
#include <stdlib.h>

typedef struct node{ int d; struct node* next; }node;
typedef struct{ node* front, * rear; }List; //List 는 두 포인터 변수를 가진다

List* Create(){
	List* list = (List*)malloc(sizeof(List));
	list->front = list->rear = 0;
	return list;
}

void push(List* list, int data){
	node* nNode = (node*)malloc(sizeof(node));
	nNode->d = data; nNode->next=0;

	node* now = list->front;
	if (!now){ //if list empty
		list->front = list->rear = nNode;
		return;
	}

	//if not empty
	//현재의list의 rear노드의 next를 이 노드로 가르킨다를 이 노드로 가르킨다
	list->rear->next= nNode; 
	list->rear = nNode;  // 현재의 list->rear가 이 노드를 가르키게한다

}

void print(List* list){
	node* now = list->front;
	if (!now) {printf("empty list\n"); return; }
	int cnt =1;
	while(now){
		printf("[%d] : %d\n", cnt++, now->d);
		now= now->next;
	}
}

int get_sum(List* list){
	node* now = list->front;
	int sum =0;
	while(now){
		sum+= now->d;
		now= now->next;
	}
	return sum;
}

int main(){

	List* list = Create(); 

	push(list, 1); push(list, 3);
	push(list, 5); push(list, 7); push(list, 9);

	print(list);
	printf("%d\n", get_sum(list));
}

