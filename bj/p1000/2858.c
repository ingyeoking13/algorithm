#include <stdio.h>

int main(){

	int r, b; scanf("%d %d", &r, &b);
	int t=r+b, ans;
	for (int i=t/2; i>2; i--){
		if (t%i==0){
			if (t/i*2+i*2-4==r) { ans=i; break; }
		}
	}
	printf("%d %d\n", ans, t/ans);
}
