#include <stdio.h>

char passwd[4], str[4];
int main(){
	scanf("%s", passwd);

	int T, num=0, chk=0;
	scanf("%d", &T);
	while (T--) {
		scanf("%s", str);
		if (str[0]==passwd[0] && str[1] == passwd[1]) chk=4;
		else if (str[1]==passwd[0] && str[0]==passwd[1]) chk=4;
		else if (str[0]==passwd[1]){
			if (chk<4){
				if (chk==1) chk=4;
				else chk=2;
			}
		}
		else if (str[1]==passwd[0]){
			if( chk<4) {
				if (chk==2) chk=4;
				else chk=1;
			}
		}
	}

	if (chk==4) printf("YES\n");
	else printf("NO\n");

}
