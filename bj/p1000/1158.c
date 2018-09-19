#include <stdio.h>

int a[5001];
int main(){
	int n, m; scanf("%d %d", &n, &m);

	int now=m, cnt=n;
	a[m]=1;
	printf("<");
	while(cnt--){
		printf(cnt?"%d, ":"%d>\n", now?now:n); 
		a[now?now:n]=1;
		int k=m;
		while(k--){
			if (!cnt) break;
			now++;
			if (now==n+1) now=1;
			if (a[now]) k++;
		}
	}
}
