#include <stdio.h>

int d[10001], coin[100];
int main(){
	int n, k; scanf("%d %d", &n, &k);
	for (int i=0; i<n; i++) scanf("%d", &coin[i]);

	d[0]=1;
	for (int i=0; i<n; i++){
		for (int j=1; j<=k; j++){
			if (j-coin[i]>=0){
				d[j]+=d[j-coin[i]];
			}
		}
	}
	printf("%d\n", d[k]);
}
