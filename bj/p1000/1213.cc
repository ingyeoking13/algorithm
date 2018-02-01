#include <bits/stdc++.h>

using namespace std;
char s[51];
int a[26];
int main(){
	scanf("%s", s);
	int len = strlen(s);
	for (int i=0; i<len; i++) a[s[i]-'A']++;

	sort(s, s+len);
	int chk=1;
	if (len%2){
		for (int i=0; i<26; i++) if (a[i]%2) chk--;
	}
	else{
		chk=0;
		for (int i=0; i<26; i++) if (a[i]%2) chk--;
	}

	if (chk) printf("I'm Sorry Hansoo\n");
	else{
		int chk2=0; char tmp;
		for (int i=0; i<len; i+=2) {
			if (a[s[i]-'A']%2 && !chk) {
				chk2=i; 
				tmp=s[i];
				i++; chk=1;
			}
			if (i<len) printf("%c", s[i]);
		}
		if(chk) printf("%c", tmp);

		for (int i=len-1; i>=0; i-=2) {
			if (i== chk2) i--;
			printf("%c", s[i]);
		}
		printf("\n");
	}
}
