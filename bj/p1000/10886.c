#include <stdio.h>

int main(){
	int n; scanf("%d", &n);
	int ans=0;
	for (int i=0; i<n; i++) {
		int tmp; scanf("%d", &tmp);
		ans+=tmp;
	}
	if( 2*ans < n ) printf("Junhee is not cute!\n");
	else printf("Junhee is cute!\n");

}
