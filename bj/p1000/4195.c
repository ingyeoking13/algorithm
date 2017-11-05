#include <stdio.h>

int parent[2000000];
int ufind(int n){
	if (n==parent[n]) return n;
	else return parent[n]=ufind(parent[n]);
}

int main(){
	int T; scanf("%d", &T);
	while(T--){
		int f; scanf("%d", %f);
		while(f--){
			char a[21], b[21];
			scanf("%s %s", a, b);



		}
	}

}
