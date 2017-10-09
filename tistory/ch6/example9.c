//nested loop
#include <stdio.h>
int main(){

	int ans=0;
	for (int i=0; i<10; i++){
		for (int j=0; j<9; j++){
			for (int k=0; k<8; k++){
				for (int l=0; l<7; l++){
					for (int m=0; m<6; m++){
						for (int n=0; n<5; n++){
							ans++;
						}
					}
				}
			}
		}
	}
	printf("%d\n", ans);
}

