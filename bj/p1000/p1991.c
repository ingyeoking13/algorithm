//tree fundamental 
#include <stdio.h>

typedef struct{
	char left, right;
}tree;
tree t[110];

void pre(int n){
	printf("%c", n);
	if ('A'<=t[n].left && t[n].left<='Z'){ pre(t[n].left); }
	if ('A'<=t[n].right && t[n].right<='Z'){ pre(t[n].right); }
}

void ino(int n){
	if ('A'<=t[n].left && t[n].left<='Z'){ ino(t[n].left); }
	printf("%c", n);
	if ('A'<=t[n].right && t[n].right<='Z'){ ino(t[n].right); }
}

void pos(int n){

	if ('A'<=t[n].left && t[n].left<='Z'){ pos(t[n].left); }
	if ('A'<=t[n].right && t[n].right<='Z'){ pos(t[n].right); }
	printf("%c", n);
}

int main(){

	char r; int n; int now;
	scanf("%d", &n);

	for (int i=0; i<n; i++){
		scanf(" %c", &r); 
		scanf(" %c %c", &t[r].left, &t[r].right);
	}

	pre('A'); printf("\n");
	ino('A'); printf("\n");
	pos('A'); printf("\n");

}
