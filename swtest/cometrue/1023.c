#include <stdio.h>
#include <string.h>

char in[5000], pre[5000], ans[1000];
int chkspecial(int s){
	int chk=1;
	for (int i=s; i<s+5; i++){
		if ((('0'<=in[i] && in[i]<='9')==0) && (('A'<=in[i] && in[i]<='Z')==0))  chk=0;
	}
	return chk;
}
int main(){

	int m[43]= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
	 0, 0, 0, 0, 0, 0, 0, 10, 11, 12,
	 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
	 23, 24, 25, 26, 27, 28, 29, 30, 31, 32,
	 33, 34, 35
	};

	scanf("%s", in);
	int n=strlen(in);

	int t=0, last=0, h=0;
	for (int i=0; i<n; i++){
		if (chkspecial(i)){
			i+=4;
		}
	}
	while (h<t){
		if (h%5) printf("%c", ans[h]); 
		else {
			if (h%25) { 
				printf("-%c", ans[h]);
				if (h%25==24) last=0;
			}
			else printf("\n%c", ans[h]);
		}
		h++;
	printf("\n");
}
