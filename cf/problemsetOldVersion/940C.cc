#include <bits/stdc++.h>

using namespace std;
char a[100002];
char b[26], c[100002];

int go(int now){

	int chk=0;
	for (int i=a[now]-'a'+1; i<26; i++){
		if ( b[i] ) {
			chk=1;
			c[now]=i+'a';
			break;
		}
	}
	if (chk) return now;
	return go(now-1);
}

int main(){
	int n, k; scanf("%d %d", &n, &k);
	scanf("%s", a);

	int min = 300;
	for (int i=0; i<n; i++){
		if ( !b[a[i]-'a']  ) b[a[i]-'a'] =1;
		if ( min > a[i]-'a' ) min=a[i]-'a';
	}

	strcpy(c, a);
	int now = go(k-1);
	int len = strlen(a);
	len = now+1>len?len:now+1;
	for (int i=len; i<k; i++){
		c[i]=min+'a';
	}
	c[k]=0;
	printf("%s\n", c);
}
