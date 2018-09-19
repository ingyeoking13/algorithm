#include <stdio.h>

int a[101];
int main(){
	int T; scanf("%d", &T);
	while(T--){
		int n; scanf("%d", &n);
		for (int i=1; i<=100; i++) a[i]=0;
		for (int i=1; i<=n; i++){
			for (int j=i; j<=n; j+=i){
				a[j]^=1;
			}
		}
		int ans=0;
		for (int i=1; i<=n; i++) if (a[i]) ans++;
		printf("%d\n", ans);
	}
}
