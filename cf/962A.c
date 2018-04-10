#include <stdio.h>

int a[200001];
int main(){

	int n; scanf("%d", &n);
	long long sum=0;

	for (int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
	  sum+= (long long)a[i];
	}

	long long tmp=0; int ans=0;
	for (int i=1; i<=n; i++){
		tmp+= (long long)a[i];
		if(tmp>= (sum)/2+sum%2) {
			ans=i;
			break;
		}
	}
	printf("%d\n", ans);


}
