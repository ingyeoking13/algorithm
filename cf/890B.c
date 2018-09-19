#include <stdio.h>

int a[200001], b[200001];
int main(){
	int n;
	scanf("%d", &n);

	for (int i=0; i<n; i++) scanf("%d", &a[i]);
	int ans;
	while(n--) if(!b[a[n]]) b[a[n]]=1, ans=a[n];
	printf("%d\n", ans);
}
