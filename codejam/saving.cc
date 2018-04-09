#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
	int T; scanf("%d", &T);
	for(int t=1; t<=T; t++){
		int n; char s[31];
		scanf("%d %s", &n, s);
		getchar();

		int len = strlen(s);
		int cnts =0, cntc=0;

		for (int i=0; i<len; i++) {
			if (s[i] == 'C') cntc++; 
			else cnts++;
		}

		if ( n < cnts) { printf("Case #%d: IMPOSSIBLE\n", t); continue; }

		int sum =0, now=1;
		for (int i=0; i<len; i++) {
			if(s[i] =='C' ) now*=2;
			else sum+=now;
		}

		int chk=0, ans=0;
		if ( sum <= n) {
			printf("Case #%d: %d\n", t, ans);
			continue;
		}

		for (int i=len-1; i>=0; i--){
			if (s[i] == 'S') continue; 

			for (int j=i; j<len; j++){
				if ( s[j+1] == 'S')  {
					s[j] ='S', s[j+1] ='C';
					sum-=now, ans++;
					sum+=(now/2);
					if ( sum <= n) {chk=1; break;}
				}
				else { now/=2;break;}
			}
			if( chk) break;
		}
		printf("Case #%d: %d\n", t, ans);
	}
}
