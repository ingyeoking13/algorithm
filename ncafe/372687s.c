//만약 개수가 정적이라면
//if problem has static size. -ZFC
#include <stdio.h>

int a[7]={0, 1, 2, 3, 4, 5, 6};
int b[7];

int main(){

	for (int i=0; i<7; i++){
		b[i]=1;
		for (int j=0; j<7; j++){
			if ( !b[j] ){
				b[j]=1;
				for (int k=0; k<7; k++){
					if ( !b[k] ){
						b[k]=1;
						for (int l=0; l<7; l++){
							if ( !b[l] ){
								b[l]=1;
								for (int m=0; m<7; m++){
									if ( !b[m] ){
										b[m]=1;
										for (int n=0; n<7; n++){
											if ( !b[n] ){
												b[n]=1;
												for (int o=0; o<7; o++){
													if ( !b[o] ){
														printf("%c%c%c%c%c%c%c\n",
																a[i]+'a',a[j]+'a',a[k]+'a',
																a[l]+'a',a[m]+'a',a[n]+'a',
																a[o]+'a');
													}
												}
												b[n]=0;
											}
										}
										b[m]=0;
									}
								}
								b[l]=0;
							}
						}
						b[k]=0;
					}
				}
				b[j]=0;
			}
		}
		b[i]=0;
	}

}
