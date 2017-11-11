#include <stdio.h>

int n;
void dfs(int i, char* oper){
	if (i>=n){
		int tmp=0, now=0, chk=1; 

		for (int j=1; j<=n; j++){
			if (oper[j]==' ') {
				tmp=tmp*10+j*10;
			}
			else {
				if (chk) now+=tmp+j; 
				else now=now-tmp-j;
				tmp=0;
				if (oper[j]=='-') chk=0;
				else chk=1;
			}
		}
		if (now==0){
			for (int j=1; j<=n; j++){
				printf("%d", j);
				printf(j==n?"":"%c", oper[j]);
			}
			printf("\n");
		}
		return ;
	}

	char* nextoper = oper;
	nextoper[i]=' ';
	dfs(i+1, nextoper );
	nextoper[i]= '+';
	dfs(i+1, nextoper );
	nextoper[i]='-';
	dfs(i+1,  nextoper );

}
int main(){

	int T; scanf("%d", &T);
	while(T--){

		scanf("%d", &n);
		char ch[20];
		for(int i=0; i<20; i++) ch[i]=0;
		dfs(1,ch);
		printf("\n");
	}
}
