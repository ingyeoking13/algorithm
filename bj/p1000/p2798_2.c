#include <stdio.h>

int n, obj, a[101];
long long ans=0;
int main(){

	scanf("%d %d", &n, &obj); 
	for (int i=0; i<n; i++){ scanf("%d", &a[i]); }

	for (int i=0; i<n; i++){
		for (int j=i+1; j<n; j++){
			for (int k=j+1; k<n; k++){
				int tmp=a[i]+a[j]+a[k];
				ans=ans>tmp||tmp>obj?ans:tmp;
			}
		}
	}

	printf("%lld\n", ans);

}
