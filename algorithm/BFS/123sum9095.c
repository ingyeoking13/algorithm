#include <stdio.h>

int bfs(int sum, int goal, int count){

	int now=0;
	if(sum==goal) return 1;
	else if (sum>goal)  return 0;
	else {
		now += bfs(sum+1, goal, count+1);
		now += bfs(sum+2, goal, count+1);
		now += bfs(sum+3, goal, count+1);
	}
	return now;
}
int main(){

	int T;
	scanf("%d", &T);

	while(T--){
	  int goal;
		scanf("%d", &goal);
		printf("%d\n", bfs(0, goal, 0));
	}
	return 0;
}
