/*
	 0. 문자열 생성 ->  ->1. append all at end string O..
	 2. append 'at' pos string O..
	 4. del node 'at' pos  O..
	 7. print all list O..
	 9. length string O..
	 6. destroy all string  O..
	 8. reverse string O..

	 3. replace "A" with "B"   find pattern
	 5. delete pattern string  find pattern
	 10. palindromic ...chk 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{ char c; struct node* next; }node ;
typedef struct { node* front,* rear; }string ;

void append(string* str, const char* c){ // append  1func.
	int len = strlen(c);
	for (int i=0; i<len; i++){
		node* newN = (node*)malloc(sizeof(node));
		newN->c= c[i]; newN->next=0;

		if ( !str->front ){ str->front = str->rear = newN; continue; }
		str->rear->next = newN;
		str->rear = newN;
	}
}

int insert(string* str, int pos, const char* s){ //2func
	node* now = str->front; 

	for (int i=0; i<pos; i++){
		if ( !now ) return 0; // has no that pos
		now = now->next;
	}

	int len = strlen(s);
	if (now == str->rear) { //pos is last pos 
		append(str, s); 
		return 1; 
	}

	node* before = now;
	node* rest = now->next; 

	for (int i=0; i<len; i++){
		node* newN = (node*) malloc(sizeof(node));
		newN->c = s[i], newN->next=0;
		before->next = newN;
		before = newN;
	}
	before->next = rest;
}
 
void print(string* str){ //7 func
	node* now = str->front;
	if (!now) printf("err! empty string");
	while(now) {
		printf("%c", now->c);
		now=now->next;
	}
	printf("\n");
}

string* create_str(const char* s){ // init 0 func.
	string* newstr = (string*)malloc(sizeof(string));
	newstr->front= newstr->rear= 0;

	append(newstr, s);

	return newstr;
};

void del_node(string* str, int pos){ // 4 func.
	node *now = str->front;

	if ( pos == 0) { // if pos == 0, ... next will become front
		str->front = now->next;
		free(now);
		return;
	}

	node *before; // else ... 
	for (int i=0; i<pos; i++)  {
		if(!now) return;
		before = now;
		now= now->next;
	}
	before->next = now->next;
	free(now);
}

int go(node* now, const char* s, int idx){ 

}

int delete(string* str, const char* s){ // 5 func.
	for (node* now= str->front; now; now=now->next){
		if ( go(now, s, 0) ) return 1;
	}
	return 0;
}

void destroy(string* str){ //6 func.
	node* before=0;
	for ( node* now = str->front; now; now=now->next){
		printf("%c", now->c);
		before=now;
		free(before);
	}
	printf("\n");
	str->front=0;
}

void reverse(string* str){
	node* before=0;
	node* now = str->front; 
	str->rear = now;
	node* next= now->next;

	while(now){
		now->next=before;
		before=now; 
		now=next;
		if(next) next = now->next;
	}
	str->front= before;
	print(str);
}

int length(string* str){ //9 func.
	int ret=0;
	for (node* now = str->front; now; now= now->next) ret++;
	return ret;
}

/*
int replace(string* str, const char* f, const char* t){
	node* now = str->front;
	int i=0;
	while(now){
		if( match(now, 0, f) ){
			del
			insert(str, i, t);
		};
		i++;
		now = now->next;
	}
}
*/


int main(){

	string* str = create_str("data"); print(str);
	append(str, "kimchi"); print(str);
	insert(str, 2, " be "); print(str);
	del_node(str, 2); print(str);
	//destroy(str); print(str);
	reverse(str);
}
