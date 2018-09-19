#include <stdio.h>

int main(){
	int ans=0;
	char str[50];

	for (int i=0; i<8; i++){
		scanf("%s", str);
		for (int j=0; j<8; j++){
			if ((i+j)%2==0 && str[j]=='F') ans++;
		}
	}

	printf("%d\n", ans);
}
