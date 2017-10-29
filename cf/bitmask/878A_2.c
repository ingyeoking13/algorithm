#include <stdio.h>

int a=0, b=1023;
int main(){
	int n; scanf("%d", &n);
	while(n--){
		char ch; int v;
		scanf(" %c %d", &ch, &v);
		if (ch=='|') a|=v, b|=v;
		else if (ch=='&') a&=v, b&=v;
		else if (ch=='^') a^=v, b^=v;
	}
	printf("3\n& %d\n^ %d\n| %d\n", a|b,a&(1023^b), a&b);
}
