#include <stdio.h>

int a[1000000];
int main(){
	int n; scanf("%d", &n);
	int min=1<<31;
	for (int i=0; i<n; i++) {
		scanf("%d", &a[i]);
		if (min>a[i]) min=a[i];
	}

	int ans;
	double Emin=1LL<<50;
	for (int i=0; i<n; i++){
		if ( 0<= i-1 ){
			double tmp = (double)(a[i]+a[i-1])/2;
			if ( Emin >tmp ) Emin=tmp, ans=i-1;
		}
		if ( i+1 <n ){
			double tmp = (double)(a[i]+a[i+1])/2;
			if ( Emin > tmp ) Emin=tmp, ans=i;
		}
	}
	printf("%d\n",ans);
}
