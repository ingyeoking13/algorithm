#include <stdio.h>

int main(){
	int n; scanf("%d", &n);

	int sum=0, tmp, chk=1;
	for (int i=0; i<n; i++){
	 	scanf("%d", &tmp),sum+=tmp;
		if (sum>2000000000) chk=0; 
	}

	int max1=0, max2=0;
	for (int i=0; i<n; i++) {
		scanf("%d", &tmp);
		if (tmp>max1) {
			max2=max1;
			max1=tmp;
		}
		else if (tmp>max2) max2=tmp; 
	}

	if (!chk || sum>max1+max2) printf("NO\n");
	else printf("YES\n");
}
