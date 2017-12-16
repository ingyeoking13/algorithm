#include <stdio.h>

int gcd(int a, int b){ return b?gcd(b, a%b):a; }
int main(){
	int a, b, c; scanf("%d %d %d", &a, &b, &c);
	int g=gcd(a,b);
	a=a/g, b=b/g;

	int cnt=1;
	while(cnt<=b && (a*10/b)!=c){
		a*=10;
		a%=b;
		cnt++;
	}
	if (cnt>b) printf("-1\n");
	else printf("%d\n", cnt);

}
