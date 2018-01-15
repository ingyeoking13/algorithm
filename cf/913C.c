#include <stdio.h>

long long a[31];
int main(){
	int n, l; scanf("%d %d", &n, &l);

	for (int i=0; i<n; i++){
		scanf("%lld", &a[i]);
	}

	for (int i=1; i<n; i++){
		a[i]= a[i]>2*a[i-1]?2*a[i-1]:a[i];
	}
	for (int i=n; i<=30; i++){
		a[i]=2*a[i-1];
	}

	long long ans=0;
	for (int i=0; i<=30; i++){
		if (l&(1<<i)) ans+=a[i];
		else if (a[i]<ans) ans=a[i];
	}
	printf("%lld\n", ans);
}
