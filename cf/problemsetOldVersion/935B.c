#include <stdio.h>

char s[100001];
int main(){
	int n; scanf("%d", &n);
	scanf("%s", s);

	int x=0, y=0, st=3, ans=0;
	if ( s[0] == 'U' ) y++, st=1;
	else x++, st=2;

	for (int i=1; i<n; i++){
		if ( s[i] == 'U') y++;
		else x++;

		if (x>y && st==1) ans++, st=3-st;
		else if ( x<y && st==2) ans++, st=3-st;
	}

	printf("%d\n", ans);
}
