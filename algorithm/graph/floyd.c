#include <stdio.h>
#define MAX 100001

int arr[101][101];
int main(){

	int v, e, a, b, tmp;
	scanf("%d %d", &v, &e);

	for (int i=1; i<=v; i++){
		for (int j=1; j<=v; j++){
			if (i!=j ) arr[i][j]=MAX;
		}
	}

	for (int i=0; i<e; i++){
		scanf("%d %d %d", &a, &b, &tmp);
		if (arr[a][b]>tmp) arr[a][b]=tmp;
	}

	for (int k=1; k<=v; k++){
		for (int i=1; i<=v; i++){
			for (int j=1; j<=v; j++){
				if (arr[i][j]> arr[i][k]+arr[k][j]) 
					arr[i][j]=arr[i][k]+arr[k][j];
			}
		}
	}

	for (int i=1; i<=v; i++){
		for (int j=1; j<=v; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
