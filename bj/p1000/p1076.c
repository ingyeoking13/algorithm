#include <stdio.h>
#include <string.h>

long long v(char* str, int n){
	if (!strcmp(str, "black")) {
		if (!n) return 0;
		return 1;
	}
	if (!strcmp(str, "brown")) {
		if (!n) return 1;
		return 10;
	}
	if (!strcmp(str, "red")){
	 	if (!n) return 2;
		return 100;
	}
	if (!strcmp(str, "orange")){
	 	if (!n) return 3;
		return 1000;
	}
	if (!strcmp(str, "yellow")) {
		if (!n) return 4;
		return 10000;
	}
	if (!strcmp(str, "green")) {
		if (!n) return 5;
		return 100000;
	}
	if (!strcmp(str, "blue")){
	 if (!n)	return 6;
	 return 1000000;
	}
	if (!strcmp(str, "violet")){
	 	if (!n) return 7;
		return 10000000;
	}
	if (!strcmp(str, "grey")) {
		if (!n) return 8;
		return 100000000;
	}
	if (!strcmp(str, "white")){
	 	if (!n) return 9;
		return 1000000000;
	}
}

int main(){

	char str1[30], str2[30], str3[30]; long long ans;
	scanf("%s %s %s", str1, str2, str3);

	ans=v(str1,0);
	ans*=10;
	ans+=v(str2,0);
	ans*=v(str3,1);

	printf("%lld\n", ans);
}

