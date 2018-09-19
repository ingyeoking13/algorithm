#include <stdio.h>
#include <string.h>

char s[501]; int n;
int dfs(int now){
	if ( now  == n )  return 1;

	if ( s[now] == '.' ) if ( dfs(now+1) ) return 1;
	if ( now+4<=n &&  s[now] != '.' && s[now+1] != '.' 
			 && s[now+2] !='.' && s[now+3] !='.' ){

		s[now] = s[now+1] = s[now+2] = s[now+3] = 'A';
		if ( dfs(now+4) )  return 1;
	}	
	if ( now+2<=n && s[now] != '.' && s[now+1] != '.' ){
		s[now] = s[now+1] = 'B';
		if ( dfs(now+2) )  return 1;
	}	
	return 0;
}

int main(){

	scanf("%s", s);
	n = strlen(s);

	if (dfs(0)) printf("%s\n", s);
	else printf("-1\n");

}
