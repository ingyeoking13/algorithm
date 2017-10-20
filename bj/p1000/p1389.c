#include <stdio.h>

int arr[101][101];

int main(){
	int v, e, a, b;
	scanf("%d %d", &v, &e);

	for (int i=0; i<e; i++) {
		scanf("%d %d", &a, &b); 
		arr[a][b]=1;
		arr[b][a]=1;
	}

	for (int i=1; i<=v; i++){
		for (int j=1; j<=v; j++){
			if (i==j) arr[i][j]=0;
			else if (arr[i][j]==0)  arr[i][j]=5000;
		}
	}

	for (int k=1; k<=v; k++){
		for (int i=1; i<=v; i++){
			for (int j=1; j<=v; j++){
				if (arr[i][j]>arr[i][k]+arr[k][j])
					arr[i][j] = arr[i][k]+arr[k][j];
			}
		}
	}

	int min=5000, ans=0;
	for (int i=1; i<=v; i++){
		int tmp=0;
		for (int j=1; j<=v; j++){
			tmp+=arr[i][j];
		}
		if (tmp<min) {min=tmp; ans=i;}
	}
	printf("%d\n", ans);
}
