// Fail.
#include <stdio.h>
#include <string.h>

char s[2501];
int d[2501], c[2500][2500];
int main(){
	fgets(s,2501, stdin);
	printf("%c", s[n-1]);

	for(int i=0; i<n; i++) c[i][i]=1; 
	for (int i=0; i<n-1; i++) if (s[i]==s[i+1]) c[i][i+1]=1;

	for (int len=2; len<=n; len++){
		for (int i=0; i<n-len; i++){
			if(s[i]==s[i+len] && c[i+1][i+len-1]) 
				c[i][i+len]=1;
		}
	}

	d[0]=0;
	for (int i=1; i<n; i++){
		d[i]=-1;
		for (int j=0; j<=i+1; j++){
			if (c[j][i]){
				if (d[i] ==-1 || d[i] > d[j-1]+1){
					d[i]=d[j-1]+1;
				}
			}
		}
	}

	printf("%d\n", d[n-1]);
}
