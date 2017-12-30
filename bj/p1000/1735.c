#include <stdio.h>

int gcd(int a, int b) {
	return b?gcd(b, a%b):a;
}

int main(){
	int a, b; scanf("%d %d", &a, &b);
	int c, d; scanf("%d %d", &c, &d);

	int bot = b*d, top= a*d+c*b;
	int g = gcd(bot, top);
	printf("%d %d\n", top/g, bot/g);
}
