// Fail................
#include <stdio.h>
#include <stdlib.h>

typedef struct stack{ 
	int con; struct stack* next;
}stack;

void init(int a){
	s[a]=(stack *)malloc(sizeof(stack));
	s[a]->next=0;
}

void push(int a, int b){
	stack* p=s[a];
	s[a]=(stack*)malloc(sizeof(stack));
	s[a]->con=b;
	s[a]->next=p;
}

stack* s[100001];
int c[100001];

int main(){
	int n, ans=0;
	scanf("%d", &n);
	for (int i=1; i<=n; i++) init(i);

	int now, next;
	scanf("%d %d", &now, &next);
	push(now, next); push(next, now);
	c[now]=0; c[next]=1;

	for (int i=1; i<n-1; i++) {
		scanf("%d %d", &now, &next);
		push(now, next); push(next, now);
		if(c[now]) c[next]=0;
		else c[next]=1;
	}
		
	for (int i=1; i<=n; i++){
		for (int j=i; j<=n; j++){
			if(a[i][j]==0 && c[i] != c[j])  ans++;
		}
	}

	printf("%d\n", ans);
}
