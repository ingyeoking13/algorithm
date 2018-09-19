#include <stdio.h>
#include <string.h>

char s[1000][200];
int main(){
	while(1){
		int n; scanf("%d", &n);
		if ( !n ) break;
		getchar();
		memset(s, 0, sizeof(s));
		for (int i=0; i<n; i++) {
			scanf("%s[^\n]", s[i]);
		}

		int cur=0;
		for (int i=0; i<n; i++){
			for (int j=cur; j<102; j++){
				if ( s[i][j] == ' ' ) {
					cur=j; 
					break;
				}
			}
		}
		printf("%d\n",cur+1);
	}
}
