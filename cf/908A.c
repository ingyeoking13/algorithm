#include <stdio.h>

int main(){
	char s[51]; scanf("%s", s);
	int ans=0;
	for (int i=0; s[i]; i++){
		if (s[i]=='a' || s[i] == 'e' || s[i] == 'i' 
				|| s[i] == 'o' || s[i] == 'u') ans++;
		else if ('0'<= s[i] &&  s[i]<= '9' && (s[i]-'0')%2) ans++;
	}
	printf("%d\n", ans);
}
