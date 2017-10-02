#include <stdio.h>
#include <stdlib.h>

typedef struct que{
	int from, to;
	struct que* next;
}que;

que* head[1001]; que* bfsa[1001];
int dfsv[1001]; int bfsv[1001];
int h=0, t=0;

void init(int from){
	head[from]=(que *)malloc(sizeof(que));
	head[from]->next=0;
}

void push(int from, int to){
	que* last= head[from];
	while(last->next){ last=last->next; }
	last->from=from; last->to=to;
	last->next=(que *)malloc(sizeof(que));
	last->next->next=0;
}

void dfs(que* now){
	if(!dfsv[now->from]) printf("%d ", now->from);
	dfsv[now->from]=1;
	if(now->to && !dfsv[now->to]){
		dfs(head[now->to]);
	}
	if(now->next->next && !dfsv[now->next->to]){
		dfs(now->next);
	}
}

void bfs(que* now){
	bfsa[t++]=now;
	printf("%d ", now->from);
	while(h<t){
		now=bfsa[h++];
		bfsv[now->from]=1;
		while(now->next){
			if(now->to && !bfsv[now->to]){
				bfsa[t++]=now->next;
				bfsv[now->from]=1;
				printf("%d ", now->to);
			}
			now=now->next;
		}
	}
}
int main(){

	int v, e, s;
	scanf("%d %d %d", &v, &e, &s);
	for(int i=1; i<=v; i++) init(i);

	int from, to;
	for(int i=0; i<e; i++){
		scanf("%d %d", &from, &to);
		push(from, to);
		push(to, from);
	}

	que *p;
	for(int i=1; i<v; i++){
		printf("%d : ", i);
		for(p=head[i];p->to;p=p->next){
			printf("%d ", p->to);
		}
		printf("\n");
	}

	dfs(head[s]); printf("\n");
	bfs(head[s]); printf("\n");
};
