#include <stdio.h>

int a[1001];
int main(){
	int n, l; 
	scanf("%d %d", &n, &l);

	for (int i=0; i<n; i++){
		int tmp;
		scanf("%d", &tmp);
		a[tmp]=1;
	}

	int ans=0;
	for (int i=0; i<=1000; i++){
		if (a[i]) {
			for (int j=0; j<l; j++) a[i+j]=0;
			ans++;
		}

	}

	printf("%d\n", ans);

}
