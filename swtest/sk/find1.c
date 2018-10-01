#include <stdio.h>

int find(int n){
	int ret=0;
	if (n%10==1) ret++;
	if (n/10) ret += find(n/10);
	return ret;
}

int main(){

	int ans=0;
	for (int i=1; i<=100000;i++){
		ans+=find(i);
	}

	printf("%d\n", ans);
}
