#include <stdio.h>

int main(){
	int n, x;
	scanf("%d %d", &n, &x);
	for (int i=0; i<n; i++){
		int a;
		scanf("%d", &a);
		x-=a;
		if (i!=n-1) x--;
	}
	if (x==0) printf("YES\n");
	else printf("NO\n");
}
