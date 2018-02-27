#include <stdio.h>

int a[3] = { 300, 60, 10 };
int main(){

	int n; scanf("%d", &n);

	int ans[3]={0, 0, 0};
	for (int i=0; i<3; i++){
		ans[i]+= n/a[i];
		n%=a[i];
	}

	if (n) printf("-1\n");
	else printf("%d %d %d\n", ans[0], ans[1], ans[2]);
}
