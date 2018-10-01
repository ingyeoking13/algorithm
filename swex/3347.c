#include <stdio.h>
#include <string.h>

int a[1000], b[1000], c[1001], cnt[1000];
int main(){
	int T; scanf("%d", &T);

	for (int t=1; t<=T; t++){
		memset(c, -1, sizeof(c));
		memset(cnt, 0, sizeof(cnt));
		int n, m; scanf("%d %d", &n, &m);
		for (int i=0; i<n; i++){
		 	scanf("%d", &a[i]);
			for (int j=a[i]; j<=1000; j++) 
				if ( c[j]<0 ) c[j]=i;
		}

		int max=0, ans=0;
		for (int i=0; i<m; i++) {
			scanf("%d", &b[i]);
			cnt[c[b[i]]]++;
			if ( max<cnt[c[b[i]]] ) max = cnt[c[b[i]]], ans=c[b[i]];
		}

		printf("#%d %d\n", t, ans+1);

	}
}
