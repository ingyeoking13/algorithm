#include <stdio.h>

int calc(int a){
	int ret=0;
	if (a%4==0) ret=a;
	if (a%4==1) ret=1;
	if (a%4==2) ret=a+1;
	 
	return ret;
}
int main(){
	int T;
	scanf("%d", &T);

	while(T--){
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", calc(a-1)^calc(b));
	}
}
