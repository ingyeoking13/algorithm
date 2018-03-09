#include <stdio.h>

int main(){
	int n; scanf("%d", &n);

	int ans=0;
	for (int i=0; i<n; i++){ 
		int tmp; scanf("%d", &tmp);
		if (tmp>= 0 ) ans+=tmp;
		else ans-=tmp;
	}
	printf("%d\n", ans);

}
