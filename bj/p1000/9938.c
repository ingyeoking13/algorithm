#include <stdio.h>

int p[300001], v[300001];
int ufind(int now){
	if ( now == p[now] ) return now;
	else return p[now] = ufind(p[now]);
}
int main(){
	int n, l; scanf("%d %d", &n, &l);
	for (int i=1; i<=l; i++) p[i]=i; 

	for (int i=0; i<n; i++){
		int a, b; scanf("%d %d", &a, &b);
		if ( !v[a] ){
			v[a]=1; 
			p[ufind(a)] = ufind(b);
			printf("LADICA\n");
		}
		else if ( !v[b] ){
			v[b]=1;
			p[ufind(b)] = ufind(a);
			printf("LADICA\n");
		}
		else if (!v[p[ufind(a)]] ){
			v[p[a]]=1;
			p[ufind(a)]=ufind(b);
			printf("LADICA\n");
		}
		else if (!v[p[ufind(b)]]){
			v[p[b]]=1;
			p[ufind(b)]=ufind(a);
			printf("LADICA\n");
		}
		else {
			printf("SMECE\n");
		}
	}
}
