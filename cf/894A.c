#include <stdio.h>
#include <string.h>

char s[101];
int main(){

	scanf("%s", s); 
	int len=strlen(s);

	int ans=0;
	for (int i=0; i<len-2; i++){
		for (int j=i+1; j<len-1; j++){
			for (int k=j+1; k<len; k++){
				if (s[i]=='Q' && s[j]=='A' && s[k] == 'Q') ans++;
			}
		}
	}
	printf("%d\n", ans);
}
