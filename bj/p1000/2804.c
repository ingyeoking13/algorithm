#include <stdio.h>
#include <string.h>

char a[32], b[32];
int main(){
	scanf("%s", a); scanf("%s", b);
	int n = strlen(a), m = strlen(b);

	int x=0, y=0, chk=0;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if ( a[i] == b[j] ) {
				x=j, y=i;
				chk=1;
				break;
			}
		}
		if (chk) break;
	}

	for (int i=0; i<m; i++){
		for (int j=0; j<n; j++){
			
			if ( i == x) printf("%c", a[j]);
			else if ( j == y) printf("%c", b[i]);
			else printf(".");

		}
		printf("\n");
	}
}
