#include <stdio.h>

int main(){

	int i, n, k, changes;
	int arr[1000000];

	//init
	scanf("%d %d",&n, &k);
	for(i=n-1;i>=0;i--) scanf("%d", &arr[i]);
	changes=0;

	for(i=0;i<n;i++) {
		changes+=k/arr[i];
		k%=arr[i];
	}
	printf("%d\n", changes);

}
