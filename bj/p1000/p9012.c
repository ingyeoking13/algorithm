#include <stdio.h>
#include <string.h>

int main(){
	int T;
	scanf("%d", &T);

	while(T--){
		char ch, in[100];
		int t=0, chk=0;
		scanf("%s", in);
		for (int i=0; in[i];i++){
			if (in[i]=='(') t++;
			else if( in[i]==')') t--;
			if (t<0) break;
		}
		if (t==0) chk=1;
		if (chk) printf("YES\n");
		else printf("NO\n");
	}
}
