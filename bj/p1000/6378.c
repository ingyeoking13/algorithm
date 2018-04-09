#include <stdio.h>
#include <string.h>

char s[1001];
int main(){
	while(1){
		scanf("%s", s);
		if (s[0]=='0') break;

		if (strlen(s)>1) {
			int now=0, next;

			for (int i=0; i<strlen(s); i++) {
				now+=(s[i]-'0');
			}

			while(1){
				next=0;

				while(now){
					next+=now%10; 
					now/=10;
				}

				if ( next/10 == 0) break;
				now= next;
			}
			printf("%d\n", next);

		}
		else printf("%s\n", s);

	}

}
