//samsung sw
#include <stdio.h>

int d[16];
int main(){
	int n, t[16], p[16];
	scanf("%d", &n);

	for (int i=1; i<=n; i++) scanf("%d %d", &t[i], &p[i]);

	for(int i=1; i<=n; i++){
		d[i]=p[i];
		for (int j=1; j<i; j++){
			if (t[j]+j<=i){ d[i]=d[j]+p[i]>d[i]?d[j]+p[i]:d[i]; }
		}
	}

	int ans=0;
	for(int i=2; i<=n; i++){
		if(t[i]+i<=n+1){
			ans=ans<d[i]?d[i]:ans;
		}
	}

	printf("%d\n", ans);
}
