#include <stdio.h>

void go(int f, int m, int t, int n){
	if ( n== 1){
		printf("%d %d\n", f, t);
		return;
	}
	go (f, t, m, n-1);
	printf("%d %d\n", f, t);
	go (m, f, t, n-1);

}
int main(){

	int n; scanf("%d", &n);
	printf("%d\n",(1<<n)-1);
	go(1, 2, 3, n);

}
