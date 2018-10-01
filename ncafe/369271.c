#include <stdio.h>
#include <stdlib.h>    

typedef struct NODE { int data; struct NODE *next; }NODE;
int main() {
	int size;
	NODE *head, *tail; //indicator
 	head=tail=0;
	printf("생성할 노드의 개수를 입력 : "); scanf("%d", &size);

	//node push!
	for (int i = 0; i < size; i++) {
		NODE *new = (NODE*)malloc(sizeof(NODE));
		printf("%d번째 노드의 데이터 : ", i + 1);
		scanf("%d", &new->data);    

		if(!head){
			head=tail=new; continue;
		}
		tail->next=new;
		tail=new;
	}
	//insert node
	int index;
	NODE *newnode = (NODE*)malloc(sizeof(NODE));
	printf("삽입할 노드의 데이터 입력 : "); 
	scanf("%d", &newnode->data);
	printf("삽입할 노드의 위치 입력 : "); 
	scanf("%d", &index);
	if(index==1){
		// [newnode --> head --> nead->next --> ...] so new one becomes head.
		newnode->next=head;
		head=newnode; 
	}
	else {
		//find prev node
		NODE* n=head;
		for(int i=2; i<index; i++){ 
			if (n->next) n=n->next; 
			else {
				printf("given index's prev_node doesn't exist!\n");
				break;
			}
		}
		if (!n->next) {
			//if (!n->next), then it means new node becomes tail.
			n->next=newnode;
			tail=newnode;
		}
		else{
			//then insert new node between two nodes.  [prev--> new --> prev->next ... ] 
			//first set new one's next = prev_node->next
			//and then set prev_node->next = new one.
			newnode->next=n->next;
			n->next=newnode;
		}
	}

	for (NODE* now = head; now; now=now->next) {
		printf("%d ", now->data);
	}
	printf("\n");
}
