#include <bits/stdc++.h>

char s[13];
long long n, tc, limit;
int main(){
	int T; scanf("%d", &T);
	while(T--){
		scanf("%s %lld %lld %lld", s, &n, &tc, &limit);
		limit *= 1e8;
		limit /= tc;

		int chk=0;
		if (!strcmp(s,"O(N)")) {if ( n > limit)  chk=1; }
		else if (!strcmp(s, "O(N^2)")) { if ( n*n > limit ) chk=1; }
		else if (!strcmp(s, "O(N^3)")) {if ( n*n*n > limit ) chk=1; }
		else if (!strcmp(s, "O(N!)"))  { 
			long long now=1; 
			for (int i=1; i<=n; i++){
				now *= (long long)i;
				if (now> limit) {
					chk=1;
					break;
				}
			}
		}
		else {
			long long now=1;
			for (int i=0; i<n; i++){
				now<<=1LL;
				if (now > limit){
					chk=1;
					break;
				}
			}
		}

		if(chk) printf("TLE!\n");
		else printf("May Pass.\n");
	}
}
