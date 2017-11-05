#include <stdio.h>

int parent[201];
int ufind(int n){
	if (n==parent[n]) return n;
	else return parent[n]=ufind(parent[n]);
}

int main(){
	int n; scanf("%d", &n);
	int travel; scanf("%d", &travel);
	for (int i=0; i<201; i++) parent[i]=i;

	int tmp;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			scanf("%d", &tmp);
			if (tmp) parent[ufind(i)]=ufind(j);
		}
	}
	int chk=1; scanf("%d", &tmp); 
	int set=ufind(tmp);
	travel--;
	while(travel--){
		scanf("%d", &tmp);
		if (set!=ufind(tmp)) chk=0;
	}
	printf(chk?"YES\n":"NO\n");
}
