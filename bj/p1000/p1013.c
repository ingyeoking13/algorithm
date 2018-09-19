#include <stdio.h>
#include <string.h>

int main(){

	int f[9][2]={{5,1},{2,-1},{3,-1},{3,4},
		{5,7},{-1,6},{5,1},{8,7},{3,6}}; 
	int T, cur;
	char s[201];
	scanf("%d", &T);
	while(T--){
		scanf("%s", s);
		int size=strlen(s);
		cur=0;
		for(int i=0; i<size; i++) {
			cur=f[cur][s[i]-'0'];
			if (cur==-1) break;
		}
		if (cur== 4||cur==7||cur==6) printf("YES\n");
		else printf("NO\n");
	}
}
