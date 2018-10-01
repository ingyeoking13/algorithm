#include <stdio.h>
int num[15];
int ans[6];
int T;
void bfs(int ind, int len) {
	if (len>=6){
		for(int i=0; i<6; i++){
			printf("%d ", ans[i]);
		}
		printf("\n");
		return;
	}
	if(ind<T){
		ans[len]=num[ind];
		bfs(ind+1, len+1);
		bfs(ind+1, len);
	}
}
int main(){

	while(1){
		scanf ("%d", &T);
		if (T==0) break;
		for (int i=0; i<T; i++) scanf("%d", &num[i]); 
		bfs(0,0);
		printf("\n");
	}
	return 0;
}
