#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct node{ node* child[26]; int cnt; int word; } node;
node* root;

char s[30];
extern void init(void){
	root = (node *) malloc(sizeof(node));
	for (int i=0; i<26; i++) {
		if ( root-> child[i] ) root->child[i]=0;
	}
	root->word=0, root->cnt=0;
};

extern void insert(int size, char *buf){
	node* now = root;
	for (int i=0; i<size; i++){
	
		if(!(now->child[buf[i]-'a'])){
			now->child[buf[i]-'a'] = (node *)malloc (sizeof(node));

			now= now->child[buf[i]-'a'];
			now->word=0, now->cnt=0;
			for (int j=0; j<26; j++) now->child[j]=0;
		}
		else now= now->child[buf[i]-'a'];

		now->cnt++;
	}
	now->word=1;
}

extern int query(int size, char *buf){
	node* now = root;
	for (int i=0; i<size; i++){
		if ( now->child[buf[i]-'a'] ){
		 	now= now->child[buf[i]-'a'];
		}
		else return 0;
	}
	int ret = now->cnt;
	return ret;
}

int main(void) {
	//freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	int TestCase; for (scanf("%d", &TestCase); TestCase--;) {
		int Query_N;
		scanf("%d", &Query_N);
		
		init();
		
		static int tc = 0;
		printf("#%d", ++tc);
		
		for (int i = 1; i <= Query_N; i++) {
			int type; scanf("%d", &type);
			getchar();

			if (type == 1) {
				char buf[15] = { 0, };
				scanf("%s", buf);
				
				int buffer_size = 0;
				while (buf[buffer_size]) buffer_size++;
				
				insert(buffer_size, buf);
			}
			else {
				char buf[15] = { 0, };
				scanf("%s", buf);
				
				int buffer_size = 0;
				while (buf[buffer_size]) buffer_size++;

				printf(" %d", query(buffer_size, buf));
			}
		}
		printf("\n");
	}
}
