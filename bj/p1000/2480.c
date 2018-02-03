#include <stdio.h>

int main(){
	int a, b, c; scanf("%d %d %d", &a, &b, &c);
	int ans=0;
	if ( a== b && b== c) { ans= 10000 + a*1000; }
	else if ( a==b || b==c || a==c) {
		if ( a==b) ans = 1000 + a*100;
		else ans = 1000 + c*100;
	}
	else {
		int max=a;
		if (max < b) max=b;
	 	if (max < c) max=c;
		ans = max*100;
	}
	printf("%d\n", ans);

}
