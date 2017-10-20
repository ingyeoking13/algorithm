#include <stdio.h>
#include <stdlib.h>

typedef struct{int v, w;}Data;
typedef struct stack{Data data;struct stack *next;}stack;

stack *head[20001];
int chk[20001], d[20001];
int v, e,f, s;

void init(int u){
	head[u]=(stack *)malloc(sizeof(stack));
	head[u]->next=0;
}
voi push(int u, Data t){
	stack *n=head[u];
	head[u]= (stack *)malloc(sizeof(stack));
	head[u]->data=t;
	head[u]->next=n;
}

int exmin(){
	int min=27331100, ans=0, t=0;
	for (int i=1;i<=s;i++){
		if(head[chk[i]] && d[chk[i]] < min){
		min=d[chk[i]];
		ans=chk[i];
		t=i;
		}
	}
	if(t) {chk[t]=chk[s];}
	return ans;
}

int main(){

	int u;
	Data t;
	scanf("%d %d %d", &v, &e, &f);
	for(int i=1; i<=v; i++){ init(i); chk[i]=i;}
	for(int i=1;i<=e;i++) {
		scanf("%d %d %d", &u, &t.v, &t.w);
		push(u, t);
	}

	for (int i=1; i<=v;i++) d[i]=27331100;
	d[f]=0;
	for(s=v;s;s--){
		u=exmin();
		stack *p;
		for(p=head[u];p;p=p->next){
			if(d[p->data.v]>d[u]+p->data.w)
				d[p->data.v]=d[u]+p->data.w;
		}
		head[u]=0;
	}
	for(int i=1; i<=v;i++){
		if(d[i]==27331100) printf("INF\n");
		else printf("%d\n", d[i]);
	}
}

