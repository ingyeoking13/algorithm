#include <stdio.h>

int main(){
	int i, n, now=210, ans, chk=1;
	scanf("%d %d", &i, &n);
	while(n--){
		int t; char ch;
		scanf(" %d %c", &t, &ch);
		now-=t;
		if (now>0) {
			if (ch=='T') if (++i>8) i=1;
		}
		else if (chk) ans=i, chk=0; 
	}
	printf("%d\n", ans);
}
