#include <stdio.h>
#include <string.h>

int main(){
	int T; scanf("%d", &T);
	while(T--)
	{
		char s[1001];
		scanf("%s", s);

		int l=0, r=strlen(s)-1;
		while(l<r) l++, r--;
		if( s[l]==s[r]) printf("Do-it\n");
		else printf("Do-it-Not\n");
	}
}
