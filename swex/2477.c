#include <stdio.h>
#include <stdlib.h>

typedef struct{ int id, t; }person;
typedef struct{ int start, t, id; }service;
service a[10], b[10]; person p[1001], q[1001];
int mycmp(const void* a, const void* b) { 
	const person *sa = (const person *) a;
	const person *sb = (const person *) b;
	return sa->t-sb->t;
}
int main(){

	int T;
	scanf("%d", &T);
	for(int test_case=1; test_case<=T; test_case++){
		int n, m, k, A, B;
		for (int i=1; i<=n; i++) scanf("%d", &a[i].t);
		for (int i=1; i<=m; i++) scanf("%d", &b[i].t);
		for (int i=0; i<k; i++) { scanf("%d",&p[i].t); p[i].id=i+1; }
		qsort(p, k, sizeof(person), mycmp);

		int time=0, h=0, t=0;
		while(t<k) q[t++]=p[h++];
		h=0;
	}
}
