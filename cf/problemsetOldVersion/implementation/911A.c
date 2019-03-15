#include <stdio.h>

int main(){
	int n; scanf("%d", &n);
	int min = 1<<30;
	int ans=1<<30, peg=0, tmp;

	while (n--){
		scanf("%d", &tmp);
		if ( min > tmp) min=tmp, peg=n;
		else if ( min == tmp ){
			if ( peg-n < ans) ans = peg-n;
			peg=n;
		}
	}

	printf("%d\n", ans);
}
