#include <stdio.h>
#include <string.h>

char s[37];
int n, ans;
int main(){

	scanf("%s %d", s, &n);
	int len = strlen(s);

	for (int i=0; i<len; i++){
		ans*=n;
		if (0<= s[i]-'0' && s[i]-'0' <=9){
			ans+=s[i]-'0';
		}
		else ans+=s[i]-'A'+10;
	}
	printf("%d\n", ans);

}
