#include <stdio.h>

int a[1000];
int main(){
	int n, A, b, c, t;
	scanf("%d %d %d %d %d", &n, &A, &b, &c, &t);
	for (int i=0; i<n; i++) scanf("%d", &a[i]);

	if (b>=c) printf("%d\n", n*A); 
	else {
		int ans =0;
		for (int i=0; i<n; i++){
			ans+= (t-a[i])*(c-b);
		}
		ans+=n*A;
		printf("%d\n", ans);
	}
}
