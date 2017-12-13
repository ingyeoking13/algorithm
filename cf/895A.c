#include <stdio.h>

int min(int x, int y) { if (x<y) return x; return y;}
int abs(int x) { if (x<0) return -x; return x;}
int a[360];
int main(){
	int n; scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", &a[i]);

	int ans=360;
	for (int i=0; i<n; i++){
		int sum=0;
		for (int j=i; j<n; j++){
			sum+=a[j];
			ans=min(ans, abs(360-2*sum));
			printf("%d\n", sum);
		}
	}
	printf("%d\n", ans);
}
