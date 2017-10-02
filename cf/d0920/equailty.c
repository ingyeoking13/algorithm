//2016 Pacific Northwest Region Programming Contest—Division 2 probelm R
#include <stdio.h>
#include <string.h>

char a[11];
int main(){

	fgets(a, 11, stdin);

	if (a[2]=='+'){
		if (a[0]-'0' + a[4]-'0' == a[8]-'0')
			printf("YES\n");
		else printf("NO\n");
	}
}
