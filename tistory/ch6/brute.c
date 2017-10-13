#include <stdio.h>

char a[6]={'a', 'b', 'c', 'd', 'e', 'f'};
int main(){
	
	for (int i=0; i<6; i++){
		for (int j=0; j<6; j++){
			for (int k=0; k<6; k++){
				for (int l=0; l<6; l++){
					printf("%c%c%c%c\n", a[i], a[j], a[k], a[l]);
				}
			}
		}
	}
}
