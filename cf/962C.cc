#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>

using namespace std;

char s[13]; 
int a[13], len, mn=50;
void dfs(int now){
	if (now ==len) {

		int fn=0;
		int tmp=0, cnt=0;
		for (int i=0; i<len; i++){
			if (a[i]){
				if (s[i]=='0' && fn==0) break;
				tmp*=10; 
				tmp+= (s[i]-'0');
				fn=1;
			}
			else cnt++;
		}	

		int chk=0;
		for (int  i=1; i<=sqrt(tmp); i++){
			if ( i*i == tmp) chk=1;
		}

		if(chk) mn = min(mn, cnt);
		
		return;
	}

	a[now]=1;
	dfs(now+1);
	a[now]=0;
	dfs(now+1);

}

int main(){
	scanf("%s", s);
	len = strlen(s);
	dfs(0);

	if (mn ==50) printf("-1\n");
	else printf("%d\n", mn);
}
