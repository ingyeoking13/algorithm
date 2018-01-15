#include <stdio.h>

int parent[1001]={0, 0}, nleaf[1001], cntnleaf[1001]={0, 0};
int main(){
	int n; scanf("%d", &n);
	for (int i=2; i<=n; i++) {
		scanf("%d", &parent[i]);
		nleaf[parent[i]]=1;
	}

	for (int i=2; i<=n; i++){
		if (!nleaf[i]) cntnleaf[parent[i]]++;
	}

	int chk=1;
	for (int i=1; i<=n; i++) {
		if (nleaf[i]){
			if (cntnleaf[i]<3) chk=0;
		}
	}
	printf(chk?"yes\n":"no\n");
}
