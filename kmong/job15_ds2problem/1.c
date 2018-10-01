#include <stdio.h>
#include <stdlib.h>

typedef struct{ int id, eng, math; }student;
typedef student element;
typedef struct ListNode{ element data; struct ListNode *link; }ListNode;
typedef struct { ListNode *front; }List; // user defined structure

List* create(){
	List* nList = (List*) malloc(sizeof(List));
	nList->front=0; return nList;
}
void swp(element* a, element* b){ element tmp = *a; *a = *b; *b = tmp; }

void push_back(List* Cl, element e){
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = e; 
	newNode->link=0;

	ListNode* now = Cl->front;
	if ( !now){
		Cl->front = newNode;
		return; 
	} // if Cl is empty

	ListNode* before; // before 
	element tmp = e; // tmp init with input "e"
	while(now){
		if ( now->data.id > tmp.id ) swp(&(now->data), &tmp); 
		before = now;
		now= now->link;
	}
	newNode->data = tmp;
	before->link  = newNode;
}

void merge(List* dCl, List* sCl) { // destination <- source
	ListNode* now  = sCl->front;
	while(now){
		push_back(dCl,now->data);
		now=now->link;
	}
}

void print(List* Cl){ // print
	ListNode* now  = Cl->front;
	while(now){
		element e = now->data;
		printf("%d %d %d\n", e.id, e.eng, e.math);
		now = now->link;
	}
}

int main(){
	printf("please input each student size class1,2. n m\n");
	int n, m; scanf("%d %d\n", &n, &m);

	List* Cl1 = create(); // Cl stands for Class List
	List* Cl2 = create();

	element tmp;
	for (int i=0; i<n; i++){
		scanf("%d %d %d", &tmp.id, &tmp.eng, &tmp.math);
		push_back(Cl1, tmp);
	}
	printf("===chk Class 1 List===\n");
	print(Cl1);
	for (int j=0; j<m; j++){
		scanf("%d %d %d", &tmp.id, &tmp.eng, &tmp.math);
		push_back(Cl2, tmp);
	}
	printf("===chk Class 2 List===\n");
	print(Cl2);
	merge(Cl1, Cl2);
	printf("===chk Class 1+2 List===\n");
	print(Cl1);
}
