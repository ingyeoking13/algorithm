#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {int kor, math, eng; }grade;
typedef struct student{ grade d; char name[100]; struct student* next; } student;
typedef struct { student* front, * rear; }List; 
void clrbuf(){ while(getchar()!='\n'){ }; }

int menu(){
	int ret=0;
	while(1){
		printf("\n==============================\n");
		printf("1. Insert a student\n");
		printf("2. Delete a student\n");
		printf("3. Calculate average\n");
		printf("4. Print all students\n");
		printf("5. Exit\n");
		printf("==============================\n");
		printf(">> ");
		scanf("%d", &ret);
		if (1<= ret && ret<=5) break;
		printf("Invalid input. 1<= .. <= 5\n");
	}
	return ret;
}

List* Create(){
	List* list = (List*)malloc(sizeof(List));
	list->front = list->rear = 0;
	return list;
}

void push(List* list, student data){
	student* nNode = (student*)malloc(sizeof(student));
	nNode->d = data.d; nNode->next=0;
	strcpy(nNode->name, data.name);

	student* now = list->front;
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
	student* now = list->front;
	if (!now) {printf("empty list\n"); return; }
	int cnt =1;
	while(now){
		printf("[%d] Name: %s\n", cnt, now->name);
		printf("[%d] Korean: %d\n", cnt, now->d.kor);
		printf("[%d] Math: %d\n", cnt, now->d.math);
		printf("[%d] English: %d\n", cnt, now->d.eng);

		cnt++;
		now= now->next;
	}
}

student* search(List* list, char* name){
	student* now = list->front;

	while(now){
		if(!strcmp(now->name, name)) return now;
	}
	return 0;
}

int delete(List* list, char* name){
	student* now = list->front;
	student* before=0;

	while(now){

		if(!strcmp(now->name, name)) {  
			// A->B->C ... we delete "B". then we need to operate "A->next = B->next" .. if only before is exist
			if(before) before->next = now->next;
			if ( list->rear == now ) list->rear =before; //if this node is first node. now->next become front;
			if ( list->front == now ) list->front = now->next; //if this node is first node. now->next become front;
			free(now);
			return 1;
		}

		before=now;
		now=now->next;
	}
	return 0;
}

int main(){
	List* list = Create();

	while(1){
		int n = menu();
		if (n==1){
			student tmp;
			printf("Name: "); scanf("%s",tmp.name); 
			printf("Korean: "); scanf("%d", &tmp.d.kor);
			printf("Math: "); scanf("%d", &tmp.d.math);
			printf("English: "); scanf("%d", &tmp.d.eng);
			push(list, tmp);
		}
		else if(n==2){
			char name[100];
			printf("Enter the name of Student: "); scanf("%s", name);
			if(delete(list, name)) printf("The data of %s is deleted\n", name);
			else printf("Not Found %s\n", name); 
		}
		else if(n==3){
			char name[100];
			printf("Enter the name of Student: "); scanf("%s", name);
			student* tmp;
			if(tmp = search(list, name)) {
				printf("%s's average is %0.1lf.\n",tmp->name, (double)(tmp->d.kor+tmp->d.math+tmp->d.eng)/3);
			}
			else printf("Not Found %s\n", name);
		}
		else if(n==4) print(list);
		else break;
	}
}
