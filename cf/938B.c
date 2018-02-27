#include <stdio.h>

int max(int x, int y){ return x<y?y:x; }
int main(){
	int n; scanf("%d", &n);
	int ans=0;
	for (int i=0; i<n; i++) {
		int tmp; scanf("%d", &tmp);
		if ( tmp <=500000 ){
			ans= max(ans, tmp-1);
		}
		else  ans = max(ans, 1000000-tmp); 
	}
	printf("%d\n", ans);

}
