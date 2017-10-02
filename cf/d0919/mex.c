#include <stdio.h>

int a[101];
int main(){

	int n, mex, ans=0;
	scanf("%d %d", &n, &mex);

	for (int i=0; i<n; i++) {
		int tmp;
		scanf("%d", &tmp);
		a[tmp]=1;
	}

	for (int i=0; i<mex; i++){
		if(a[i]==0) ans++;
	}
	if (a[mex]==1) ans++;

	printf("%d\n", ans);

}
