#include <bits/stdc++.h>

char s[101], s2[101], s3[3];
int main(){
	scanf("%s %s %s", s, s3, s2);
	int len = strlen(s);
	int len2 = strlen(s2);

	if (s3[0] == '+' ){
		if (len == len2){
			printf("2");
			for (int i=1; i<len; i++) printf("0");
		}
		else if (len > len2){
			printf("1");
			for (int i=1; i<len; i++) {
				if (len-i == len2) printf("1");
				else printf("0");
			}
		}
		else {
			printf("1");
			for (int i=1; i<len2; i++){
				if (len2-i == len) printf("1");
				else printf("0");
			}
		}
	}
	else {
		printf("1");
		for (int i=0; i<len+len2-2; i++){
			printf("0");
		}
	}
	printf("\n");
}
