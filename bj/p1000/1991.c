#include <stdio.h>

typedef struct { int lc, rc; }node;
node t[26];
void preorder(int now){
	printf("%c", now+'A');
	if (t[now].lc) preorder(t[now].lc); 
	if (t[now].rc) preorder(t[now].rc);
}

void inorder(int now){
	if (t[now].lc) inorder(t[now].lc); 
	printf("%c", now+'A');
	if (t[now].rc) inorder(t[now].rc);
}
void postorder(int now){
	if(t[now].lc) postorder(t[now].lc); 
	if(t[now].rc) postorder(t[now].rc);
	printf("%c", now+'A');
}

int main(){
	int m; scanf("%d", &m);
	while(m--){
		char p[3], lc[3], rc[3]; 
		scanf("%s %s %s", p, lc, rc);
		if( 'A' <= lc[0] && lc[0] <= 'Z') t[p[0]-'A'].lc = lc[0]-'A';
		if( 'A' <= rc[0] && rc[0] <= 'Z') t[p[0]-'A'].rc = rc[0]-'A';
	}

	preorder(0); printf("\n");
	inorder(0); printf("\n");
	postorder(0); printf("\n");
}
