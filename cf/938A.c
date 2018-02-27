#include <stdio.h>

char a[101];
int main(){
	int n; scanf("%d", &n);
	scanf("%s", a);

	int chk=1;
	for (int i=0; i<n; i++){
		if ( a[i]=='a' || a[i] == 'e' || a[i]=='i' || a[i] == 'o' || a[i]=='u' 
				 || a[i]=='y'){
			if (chk){
				printf("%c", a[i]);
				chk=0;
			}
		}
		else { 
			printf("%c", a[i]); 
			chk=1; 
		}
	}
	printf("\n");

}
