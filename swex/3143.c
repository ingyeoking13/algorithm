#include <stdio.h>
#include <string.h>

char s[10001], p[101];
int main(){
	int T; scanf("%d", &T);
	for (int t=1; t<=T; t++){
		scanf("%s %s", s, p);
		int n = strlen(s);
		
		int ans=0;
		for (int i=0; i<n; i++){
			if (!strncmp(s+i,p, strlen(p))){
				i+=strlen(p);
			 	i--; ans++;
			}
			else ans++;
		}
		printf("#%d %d\n", t, ans);
	}

}
