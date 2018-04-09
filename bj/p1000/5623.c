#include <stdio.h>

int a[1000][1000];
int ans[1000];
int main(){
	int n; scanf("%d", &n);

	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			scanf("%d", &a[i][j]);
		}
	}
	if (n ==2) return !printf("1 %d\n", a[0][1]-1);

	ans[0] = ((a[0][n-1] - a[1][n-1])+a[0][1])/2;

	printf("%d ", ans[0]);
	for (int i=1; i<n; i++){
		ans[i] = a[0][i]-ans[0];
		printf("%d ", ans[i]);
	}
	printf("\n");
}
