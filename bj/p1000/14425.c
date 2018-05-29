#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node{
	 struct node* child[26];
	 char word;
}node;
char in[20000*500+20000];
char s[501];
node* root;
node* create() {
	node* nNode = (node*)malloc(sizeof(node));
	memset(nNode, 0, sizeof(nNode));
	return nNode;
}
void push(){
	node* now = root;
	for (int i=0; s[i]; i++){
		if ( now->child[s[i]-'a'] ) now=now->child[s[i]-'a'];
		else{
			now->child[s[i]-'a']=create();
			now=now->child[s[i]-'a'];
		}
	}
	now->word=1;
	return;
}
int find(){
	node* now = root;
	for (int i=0; s[i]; i++){
		if (!now->child[s[i]-'a']) return 0;
		now=now->child[s[i]-'a'];
	}
	return now->word;
}
void get(){
	static int i=0;
	int len=0;
	while(in[i] >= 'a'){
		s[len] = in[i];
		i++, len++;
	}
	i++;
	s[len++]=0;
}

int main(){
	root = create();
	int n, m; 
	scanf("%d %d", &n, &m);
	getchar();

	fread(in, sizeof(in), 1, stdin);

	for (int i=0; i<n; i++){
		get();
		push();
	}

	int ans=0;
	while(m--){
		get();
		ans+= find();
	}
	printf("%d\n", ans);
}
