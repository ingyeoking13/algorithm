#include <stdio.h>
#include <stdlib.h>
int coin[101], d[10001];
int main(){
	int n, k; scanf("%d %d", &n, &k);
	for (int i=0; i<n; i++)	scanf("%d", &coin[i]);

	for (int i=0; i<n; i++){
		for (int j=1; j<=k; j++){
			if (j-coin[i]>=0 && (d[j-coin[i]]!=0 || !(j-coin[i]))){
				if (d[j]==0 || d[j]>d[j-coin[i]]+1){
					d[j]=d[j-coin[i]]+1;
				}
			}
		}
	}
	printf("%d\n", d[k]?d[k]:-1);
}
