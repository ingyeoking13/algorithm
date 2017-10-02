#include <stdio.h>

int a[1000][1000];
char s[2100];
int main(){
	int r, c, chk=0;
	scanf("%d %d", &c, &r);
	getchar();
	for (int i=0; i<r; i++){
		fgets(s, 2100, stdin);
		for (int j=0; j<c; j++){
			a[i][j]=s[2*j]-'0';
		}
	}

	for (int i=0; i<r; i++){
		for (int j=0; j<c; j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

}
