#include <stdio.h>

int d[1001]={0, 1, 2};
int main(){

	int n;
	scanf("%d", &n);
	for (int i=3; i<=n; i++) d[i]= (d[i-1]%10007+d[i-2]%10007)%10007;
	printf("%d\n", d[n]);
}
