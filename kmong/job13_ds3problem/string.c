/*
	 0. 문자열 생성 ->  ->1. append all at end string O..
	 2. append 'at' pos string O..
	 4. del node 'at' pos  O..
	 7. print all list O..
	 9. length string O..
	 6. destroy all string  O..
	 8. reverse string O..

	 ps find pattern O
	 5. delete pattern string  find pattern O
	 3. replace "A" with "B"   find pattern O
	 10. palindromic ...chk O
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

string* create_str(const char* s){ // init 0 func.
	string* newstr = (string*)malloc(sizeof(string));
	newstr->front= newstr->rear= 0;
	append(newstr, s);
	return newstr;
};

void insert(string* str, int pos, const char* s){ //2func
	node* now = str->front; 
	int len = strlen(s), cnt=-1, i=0;

	node* before=0;
	while(now || before){
		if(cnt>= pos && i<len){
			node* newN = (node*) malloc(sizeof(node));
			newN->c = s[i++], newN->next=0;
			if(before) before->next = newN;
			newN->next= now;
			if( now==str->front)  str->front = newN;
			if( before==str->rear) str->rear = newN;
			now = newN;
		}
		cnt++;
		before=now;
		if(now) now=now->next;
	}
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

int find(string* str, const char* f){
	node* iter = str->front;
	int flen = strlen(f), chk, pos=0;
	while(iter){
		chk=1;
		node* now = iter;
		for (int i=0; i<flen; i++, now=now->next){
			if (now->c != f[i]){
				chk=0;
				break;
			}
		}
		if (chk) return pos;
		iter=iter->next;
		pos++;
	}
	return pos=-1;
}

int replace(string* str, const char* f, const char* t){
	int pos=find(str, f), flen= strlen(f);
	if (pos>=0) {
		for (int i=0; i<flen; i++) del_node(str, pos);
		insert(str, pos-1, t);
		return 1;
	}
	printf("No Match Found \"%s\".\n", f);
	return 0;
}

int delete(string* str, const char* s){ // 5 func.
	int pos=find(str, s), slen= strlen(s);
	if (pos>=0) {
		for (int i=0; i<slen; i++) del_node(str, pos);
		return 1;
	}
	printf("No Match Found \"%s\".\n", s);
	return 0;
}

void palindrome(string* str){
	char s[1000];
	node* now = str->front;
	int slen=0, s2len=0;
	while(now){
		s[slen++]= now->c;
		now=now->next;
	}

	int chk=1;
	for (int i=0; i<slen/2; i++){
		if (s[i] != s[slen-i-1]) {
			chk=0;
			break;
		}
	}

	if (chk) printf("Palindrome\n");
	else printf("NO Palindrome\n");
}

int main(){

	string* str = create_str("aba"); print(str);
	//append(str, "kimchi"); print(str);
	//insert(str, 9, " be "); print(str);
	//del_node(str, 2); print(str);
	//replace(str, "d", "dexsex"); print(str);
	//delete(str, "dex"); print(str);
	palindrome(str);

	//destroy(str); print(str);
	//reverse(str);
}
