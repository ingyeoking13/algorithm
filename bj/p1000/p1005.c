#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int t[1001], a[1001], deg[1001], prior[1001];
typedef struct queue{ int v; struct queue* next;}queue; 
queue* q[1001];
void init(int a){
	q[a]=(queue*)malloc(sizeof(queue));
	q[a]->next=0;
}
void push(int a, int b){
	queue* p = q[a];
	while(p->next) p=p->next;
	p->v=b;
	p->next=(queue*)malloc(sizeof(queue));
}
int main(){

	int T;
	scanf("%d", &T);
	while(T--){
		memset(a, 0, sizeof(a));
		memset(deg, 0, sizeof(deg));
		int n, k, ans, head=0;
		scanf("%d %d", &n, &k);
		for (int i=1; i<=n; i++){ scanf("%d", &t[i]); init(i);}
		for (int i=0; i<k; i++) { 
			int u, v;
			scanf("%d %d", &u, &v);
			push(u, v);
			deg[v]++;
		}
		for (int i=1; i<=n; i++)
			if (!deg[i]) prior[head++]=i;

		scanf("%d", &ans);
		//start
		while(deg[ans]>0){
			for (int i=0; i<head; i++){
				int now=prior[i];
				for(queue* p= q[now];p;p=p->next){
					if(a[p->v]<t[now]+a[now]) a[p->v]=t[now]+a[now];
					if(--deg[p->v]==0) prior[head++]=p->v;
				}
			}
		}

		printf("%d\n", t[ans]+a[ans]);
	}
}
