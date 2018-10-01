#include <stdio.h>

int a[1000001], d[1000001];
int main(){
	int T;
	scanf("%d", &T);
	
	for (int t=1;t<=T; t++){
		int n, ans=1;
		scanf("%d", &n);
		for (int i=1; i<=n; i++) scanf("%d", &a[i]);
		for (int i=1; i<=n; i++) d[i]=0;

		int jump;
		scanf("%d", &jump);

		int cur=0;
		for (int i=1; i<=n; i++){
			if (a[cur]>=a[i]-jump) d[i]=d[cur]+1;
			else {
				cur=i-1;
				if (a[cur]>=a[i]-jump) d[i]=d[cur]+1;
				else break;
			}
		}

		printf("Case #%d\n%d\n", t, d[n]?d[n]:-1);
	}
}
