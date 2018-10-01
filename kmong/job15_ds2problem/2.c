#include <stdio.h>
#include <stdlib.h>

typedef struct{ int row, col, value; }element;
typedef struct ListNode{ element data; struct ListNode* link; }ListNode;
typedef struct { int rows, cols; ListNode* head,* tail; }ListHeader;
void swap(ListNode* a, ListNode* b){ 
	element tmp=a->data; 
	a->data =b->data; 
	b->data = tmp;
}

void init(ListHeader* plist, int r, int c){ // from hw sheet.
	plist->rows=r; 
	plist->cols=c;
	plist->head = plist->tail =0;
}

void print_matrix(ListHeader* plist){ // from hw sheet.
	ListNode* p = plist->head;
	while(p){
		printf("%d %d %d\n", p->data.row, p->data.col, p->data.value);
		p= p->link;
	}
}

void insert_node_last(ListHeader* plist, element e){
	ListNode* newNode  = (ListNode*) malloc(sizeof(ListNode));
	newNode->data = e; newNode->link=0; 

	ListNode* p = plist->head;

	if (!p){ // if p empty
		plist->head = plist->tail = newNode;
		return ;
	}
	plist->tail->link =  newNode; // else ...
	plist->tail = newNode;
}

void transpose(ListHeader* plist){
	ListNode* p = plist->head;
	while(p){
		int tmp = p->data.row; 
		p->data.row =  p->data.col;
		p->data.col = tmp;
		p=p->link;
	}

	for (ListNode* peg= plist->head; peg; peg= peg->link){ // for list ... just iterate "n"

		int chk = 0;
		for (ListNode* now=plist->head; now; now=now->link){  // n ^ 2 ...  but chk var. do better

			ListNode* next = now->link;
			if (!next) continue;

			if (now->data.row > next->data.row) swap(now, now->link), chk=1;
			else if ( now->data.row == next->data.row) {
				if(now->data.col > next->data.col) swap(now, now->link), chk=1;
			}
		}
		if (!chk) break;
	}
}

element a[12] ={
	{0, 0, 2}, {0, 1, 0}, {0, 2, 0}, {0, 3, 0},
	{1, 0, 0}, {1, 1, 3}, {1, 2, 0}, {1, 3, 4},
	{2, 0, -3}, {2, 1, 0}, {2, 2, 0}, {2, 3, 1}
};

int main(){
	ListHeader list1;
	init(&list1, 3, 4);
	for (int i=0; i<12; i++) insert_node_last(&list1, a[i]);
	print_matrix(&list1);
	printf("==========transpose==========\n"); 
	transpose(&list1);
	print_matrix(&list1);

}
