#include <stdio.h>
int num[21];
int T, obj, ans=0;

void bfs(int sum, int ind){
	if (ind<T) {
		int next= sum+num[ind];
		if (obj==next) ans++;
		bfs(next, ind+1);
	  bfs(sum, ind+1);
	};
}

int main(){

	scanf("%d %d", &T, &obj);
	for(int i=0; i<T; i++) scanf("%d", &num[i]);
	bfs(0, 0);

	printf("%d\n", ans);

}
