#include <stdio.h>
#include <string.h>

int main(){
	int n;
	char str[52], tmp[52];
	scanf("%d", &n);
	scanf("%s", str);
	int len = strlen(str);
	for (int i=1; i<n; i++){
		scanf("%s", tmp);
		for (int j=0; j<len; j++){
			if (str[j]!=tmp[j]){ str[j]='?';}
		}
	}
	printf("%s\n", str);
}
