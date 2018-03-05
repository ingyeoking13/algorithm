#include <stdio.h>
#include <string.h>

char s[51];
int main(){
	scanf("%s", s);
	int n= strlen(s);

	int st=0, ans=0;
	for (int i=0; i<n; i++){
		if ( s[i] == '(' ) {
			if ( st==1) ans+=5;
			else ans+=10, st=1;
		}
		else {
			if ( st==2 )  ans+=5;
			else ans+=10, st=2;
		}
	}
	printf("%d\n", ans);
}
