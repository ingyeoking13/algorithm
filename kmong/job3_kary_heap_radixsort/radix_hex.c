/*
	 radix sort
*/
#include <stdio.h>
#include <string.h>
#define BASE 16
#define LEN 10
#define MXSZ 20 //"MXSZ" the mx element that 
								//can be assigned in each BASE array 
								//(200/10==10 but for safety..20)

int SZ=0; //input elem size
int ret(char ch){ //retrieve digit from hexa
	if ('0'<= ch && ch<='9')  return ch-'0';
	return ch-'A'+10;
}

void radix(char s[MXSZ][LEN+1]){
	char a[BASE][MXSZ][LEN+1]; //the basket for radix sort
	int cnt[BASE];   					 //cnt array for usability

	for (int i=LEN-1; i>=0; i--){ //see the last char as lowest position
																//iterate over LEN (10)
		memset(a, 0, sizeof(a));
		memset(cnt, 0, sizeof(cnt));
		int sz=0;

		for (int j=0; j<SZ; j++){
			int tmp =ret(s[j][i]); // now rank
			strcpy(a[tmp][cnt[tmp]],s[j]); //put s[j] string at his rank basket
			cnt[tmp]++;
		}

		for (int j=0; j<BASE ; j++){
			for (int k=0; k<cnt[j]; k++){
				strcpy(s[sz], a[j][k]); //take "sz"th string from rank basket
				sz++;
			}
		}
		for (int j=0; j<SZ; j++) printf("%s ", s[j]);
		printf("\n");
	}
}

int main(){
	char s[MXSZ][LEN+1];
	while(~scanf("%s",s[SZ++]));
	SZ--;

	radix(s);
}
