#include <stdio.h>

int a[1001], b[1001];
int main(){
	int l; scanf("%d", &l);
	int n; scanf("%d", &n);
	int lng = 0, ans1=0;
	for (int i=1; i<=n; i++){

		int f, t; scanf("%d %d", &f, &t);
		if ( t-f > lng) lng=t-f, ans1=i;
		for (int j=f; j<=t; j++) {
			if(a[j]) continue;
			a[j]=i;
		}
	}
	for (int i=1; i<=l; i++) b[a[i]]++;

	int mx=0, ans=0;
	for (int i=1; i<=n; i++) {
		if ( mx< b[i] ) mx = b[i], ans=i;
	}
	printf("%d\n%d\n",ans1, ans); 
}
