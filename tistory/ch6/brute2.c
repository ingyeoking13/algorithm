#include <stdio.h>

char a[33];
int main(){
	for (int i=0; i<26; i++) a[i]='a'+i;
	a[26]='!', a[27]='@', a[28]='#', a[29]='$', a[30]='%', a[31]='^', a[32]='&';
	
	for (int i=0; i<33; i++){
		for (int j=0; j<33; j++){
			for (int k=0; k<33; k++){
				for (int l=0; l<33; l++){
					for (int m=0; m<33; m++){
						for (int n=0; n<33; n++){
							printf("%c%c%c%c%c%c\n", a[i], a[j], a[k], a[l], a[m], a[n]);
						}
					}
				}
			}
		}
	}
}
