#include <stdio.h>
#define max(a,b) a>b?a:b

int d[1001]={0};
int v[1001];
int main(){

	int n;
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &v[i]);

	for (int i=1;i<=n;i++)
			for (int j=1; j<=i;j++)
				d[i]=max(d[i],d[i-j]+v[j]);

	printf("%d\n", d[n]);

}
