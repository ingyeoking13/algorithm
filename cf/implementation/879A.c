#include <stdio.h>

int a[1000], b[1000];
int main(){

	int n, t=0; scanf("%d", &n);
	for (int i=0; i<n; i++){
	 	scanf("%d %d", &a[i], &b[i]);
		if (t<a[i]) t=a[i];
		else{
			while(t>=a[i]) a[i]+=b[i];
			t=a[i];
		}
	}
	printf("%d\n", t);
}
