#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MOD 1000000007

char str[10002];
int d[10002][16];
int main(){
	int T; scanf("%d", &T);
	for (int t_c=1; t_c<=T; t_c++){

		memset(d, 0, sizeof(d));
		scanf("%s", str+1);
		int days = strlen(str+1);

		d[0][8]=1;
		for (int i=1; i<=days; i++){
			int auth;
			if (str[i]=='A') auth=8;
			else if (str[i]=='B') auth=4;
			else if (str[i]=='C') auth=2;
			else auth=1;
			for (int j=0; j<16; j++){
				if (j & auth){
					for (int k=0; k<16; k++){
						if (j & k){
							d[i][j]+=d[i-1][k];
							d[i][j]%=MOD;
						}
					}
				}
			}
		}
		
		int ans=0; 
		for (int i=0; i<16; i++) ans+=d[days][i], ans%=MOD;
		printf("#%d %d\n", t_c, ans);
	}
}
