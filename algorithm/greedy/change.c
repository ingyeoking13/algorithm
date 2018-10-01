#include <stdio.h>

int main(){

	int i, money, change;

	scanf("%d", &money);
	money= 1000-money;

	change=0;
	change+=money/500;
	money=money%500;

	change+=money/100;
	money=money%100;

	change+=money/50;
	money=money%50;

	change+=money/10;
	money=money%10;

	change+=money/5;
	money=money%5;

	change+=money/1;

	printf("%d\n", change);
	return 0;
}
