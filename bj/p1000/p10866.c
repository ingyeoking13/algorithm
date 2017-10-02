#include <stdio.h>
#include <string.h>
#define MAX 3

int dq[MAX], front=-1,rear=-1;

int empty(){ return front==-1; }

void pushback(int n){
	if (front==-1) front=rear=0; 
	else if (rear==MAX-1) rear=0;
	else rear++;
	dq[rear]=n;
}

void pushfront(int n){
	if (front==-1) front=rear=0;
	else if (front==0) front=MAX-1;
	else front--;
	dq[front]=n;
}

int popfront(){
	int ret=dq[front];
	if (empty()) ret=-1; 
	else{
		if (front == rear) front = rear = -1; 
		else if (front==MAX-1) front=0; 
		else front++; 
	}
	return ret;
}	

int popback(){
	int ret=dq[rear];
	if (empty()) ret=-1; 
	else{
		if (front == rear) front = rear = -1; 
		else if (rear==0)  rear=MAX-1; 
		else  rear--; 
	}
	return ret;
}	

int ffront(){ if (empty()) return -1; return dq[front]; }
int back(){ if (empty()) return -1;  return dq[rear]; }

int size(){ 
	int ret;
	if (front==-1) ret=0;
	else if (front >rear) ret=MAX-front-rear+1; 
	else ret=rear-front+1;
	return ret;
}

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		char str[51];
		int n; 
		scanf("%s", str);
		if (!strcmp(str,"push_back")) {
			scanf("%d", &n); 
			pushback(n);
		}

		else if (!strcmp(str,"push_front")){
			scanf("%d", &n);
		 	pushfront(n);
		}

		else if (!strcmp(str,"pop_front")) printf("%d\n", popfront()); 
		else if (!strcmp(str,"pop_back")) printf("%d\n", popback()); 
		else if (!strcmp(str,"front")) printf("%d\n", ffront()); 
		else if (!strcmp(str,"back")) printf("%d\n", back()); 
		else if (!strcmp(str,"size")) printf("%d\n", size()); 
		else if (!strcmp(str,"empty")) printf("%d\n", empty()); 
	}
}
