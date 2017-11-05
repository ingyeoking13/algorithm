#include <stdio.h>

int parent[1000001];
int find(int n){
	if (n==parent[n]) return n;
	else return find(parent[n]);
}
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i=1; i<=n; i++) parent[i]=i;
	while(m--){
		int op, a, b;
		scanf("%d %d %d", &op, &a, &b);
		if (op) printf(find(a)==find(b)?"YES\n":"NO\n");
		else{
			parent[find(a)]=find(b);
		}
	}
}
