#include<stdio.h>

int oddnum(int num)        //홀수값만 원함
{
	 if (num % 2 == 0) return 0; 
	else return printf("%d\n", num);
}

int main(){

	oddnum(3);
	oddnum(2);

	return 0;
}
