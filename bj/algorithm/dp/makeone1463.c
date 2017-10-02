#include <stdio.h>

int d[1000000];

int dp(int n){
	if (n==1) return 0;
	d[n]=dp(n-1)+1;
	if (!(n%2)) {
		int tmp= dp(n/2)+1;
		if (d[n]>tmp) d[n]=tmp;
	}
	if (!(n%3)){
		int tmp=dp(n/3)+1;
		if (d[n]>tmp) d[n]=tmp;
	}
	return d[n];
}

int main(){

	int num;
	scanf("%d", &num);
	dp(num);
	printf("%d\n", d[num]);

}
