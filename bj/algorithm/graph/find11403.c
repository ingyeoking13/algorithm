#include <stdio.h>

int a[101][101];
int main(){
	int n;
	scanf("%d", &n);

	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			scanf("%d", &a[i][j]);
		}
	}

	for (int k=0; k<n; k++){
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				if (a[i][j]<a[i][k]+a[k][j]) 
					if(a[i][k] && a[k][j]) a[i][j]=1;
			}
		}
	}

	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

}
