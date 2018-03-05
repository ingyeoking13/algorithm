#include <stdio.h>

int a[20];
int main(){

	int n, k; scanf("%d %d", &n, &k);
	for (int i=0; i<n; i++) scanf("%d,", &a[i]);

	while(k--){

		for (int i=0; i<n-1; i++){
			a[i]= a[i+1]-a[i];
		}
		n--;

	}
	for (int i=0; i<n; i++) {
		printf("%d", a[i]);
		if(i<n-1) printf(",");
	}
	printf("\n");


}
