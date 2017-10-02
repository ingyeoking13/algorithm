//최소 스패닝 트리
#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int a, b, w;
}edge;

edge e[100001];
int rep[10001];

int mycmp(const void* a, const void* b){
	const edge *sa = (const edge *)a;
	const edge *sb = (const edge *)b;
	return sa->w-sb->w;
}

int find(int x){
	if (x==rep[x]) return x;
	else return rep[x]=find(rep[x]);
}

int main(){
	int v, en;
	scanf("%d %d", &v, &en);
	for (int i=0; i<v; i++) rep[i]=i;

	for (int i=0; i<en; i++) scanf("%d %d %d", &e[i].a, &e[i].b, &e[i].w);

	qsort(e, en, sizeof(edge), mycmp);

	int ans=0;
	for(int i=0; i<en; i++){
		int r1=find(e[i].a), r2=find(e[i].b);
		if (r1==r2) continue;
		rep[r2]=r1;
		ans+=e[i].w;
	}
	printf("%d\n", ans);
	return 1;
}

