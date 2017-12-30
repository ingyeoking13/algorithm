#include <stdio.h>

int a[1501], ans;
int main(){
	int n; scanf("%d", &n);
	for (int i=1; i<=n; i++) scanf("%d", &a[i]);

	for (int i=1; i<=n; i++)
		for (int j=i+1; j<=n; j++)
			if (a[i]>a[j]) ans^=1;

	int m; scanf("%d", &m);
	while(m--){
		int l, r;
		scanf("%d %d", &l, &r);
		if (((r-l)*(r-l+1)/2)%2) ans^=1;
		if (ans) printf("odd\n");
		else printf("even\n");
	}
}
