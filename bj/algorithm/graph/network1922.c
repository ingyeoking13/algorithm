#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int a, b, w;
}Edge;

Edge e[100001];
int rep[1001];

int mycmp(const void* a, const void *b){
	const Edge *sa = (const Edge*)a;
	const Edge *sb = (const Edge*)b;
	return sa->w-sb->w;
}

int find(int x){
	if (x==rep[x]) return x;
	else return (rep[x] = find(rep[x]));
};

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i=0; i<m ; i++) 
		scanf("%d %d %d", &e[i].a, &e[i].b, &e[i].w);
	for(int i=0; i<=n; i++) rep[i]=i;

	qsort(e, m, sizeof(Edge), mycmp); 

	int ans=0;
	for (int i=0; i< m ; i++){
		int r1 = find(e[i].a), r2 = find(e[i].b);
		if (r1==r2) continue;

		rep[r2]=r1;
		ans+=e[i].w;
	}

	printf("%d\n", ans);
	return 0;
}
