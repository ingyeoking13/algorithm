#include <stdio.h>

long long a[5000000];
int main(){
	int n, k; scanf("%d %d", &n, &k);

	for(int i=0; i<n; i++) scanf("%d", &a[i]);
	long long m1=1LL<<60, m2=1LL<<60;

	for (int i=0; i<k; i++) {
		if (a[i]<m1) m2=m1, m1=a[i];
		else if ( a[i]<m2 ) m2=a[i];
	}
	for (int i=0; i<n; i++){
		printf("%d\n", m1);


	}

}
