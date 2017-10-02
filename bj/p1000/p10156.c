#include <stdio.h>
int main(){
	int k, n, m, ans;
	scanf("%d %d %d", &k, &n, &m);
	ans=m-n*k;
	if (-ans<0) printf("%d\n", 0);
	else printf("%d\n", -ans);
}
