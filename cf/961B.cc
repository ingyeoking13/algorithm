#include <stdio.h>
#include <algorithm>

using namespace std;
int a[100001];
int b[100001];
int s[100001], s2[100001];
int main(){

	int n, k; scanf("%d %d", &n, &k); 
	for(int i=1;i<=n; i++) scanf("%d", &a[i]);
	for(int i=1;i<=n; i++) scanf("%d", &b[i]);

	s[1]=a[1]*b[1];
	for (int i=2; i<=n; i++)  s[i] += (a[i]*b[i])+s[i-1];
	int mymax=s[n];

	s2[1] = a[1]*(1-b[1]);
	for (int i=2; i<=n; i++)  s2[i] += (a[i]*(1-b[i]))+s2[i-1];
//	for (int i=1; i<=n; i++)  printf("%d\n", s2[i]);

	int ans=mymax, mx=0;
	for (int i=k; i<=n; i++){
		mx = max(mx, s2[i]-s2[i-k]);
	}
	printf("%d\n", ans+mx);
}
