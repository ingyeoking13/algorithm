#include <bits/stdc++.h>

using namespace std;

char s[100002];
int main(){

	scanf("%s", s);
	int n = strlen(s);
	int now= 'a', cnt=0, ans[26];

	for (int i=0; i<n; i++){
		if ( s[i] <= now ) {
			ans[cnt++]=i; 
			now+=1;
		}

		if ( cnt == 26) break;
	}

	if (cnt>=26){
		for (int i=0; i<26; i++){
			s[ans[i]] = 'a'+i;
		}
		printf("%s\n", s);
	}
	else printf("-1\n");
	
}
