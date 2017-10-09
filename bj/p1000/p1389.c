#include <stdio.h>

int arr[101][101], d[101][101]; 
int min(int a, int b){
	if (a<b) return a;
	return b;
}

int dfs(int a, int b){


}

int main(){
	int v, e, a, b;
	scanf("%d %d", &v, &e);

	for (int i=0; i<e; i++) {
		scanf("%d %d", &, &b); 
		arr[a][b]=1;
		arr[b][a]=1;
	}




	int min=1000;
	for (int i=1; i<=100; i++){
		int tmp=0;
		for (int j=1; j<=100; j++){
			tmp+=d[i][j];
		}
		if (min>tmp) {
			min=tmp;
			ans=i;
		}
	}

	printf("%d\n", ans);

}
