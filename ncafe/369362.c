#include <stdio.h>
#include <string.h>

char a[200], b[200], c[200];

int chk(char ch1, char ch2){
	ch1-='0', ch2-='0';

	if ( 0<= ch1 && ch1<=9 && 0<= ch2 && ch2<=9) return 1;
	else if ( 0<= ch1 && ch1<=9) return 2; 
	else if ( 0<= ch2 && ch2<=9) return 3;
	return 0;
}
int main(){

	scanf("%s", a); scanf("%s", b);
	int len=strlen(a);
	for (int i=len-1 ; i>=0; i--){
		int now=i; 
		while (now+1<200 && a[now+1]==0) now++; 
		a[now]=a[i];
		a[i]=0;
	}

	len=strlen(b);
	for (int i=len-1 ; i>=0; i--){
		int now=i; 
		while (now+1<200 && b[now+1]==0) now++; 
		b[now]=b[i];
		b[i]=0;
	}

	int over=0;
	for(int i=199; i>=0; i--){
		int d=chk(a[i], b[i]), tmp=0;

		if (d==1) tmp=a[i]-'0'+b[i]-'0'; 
		else if (d==2) tmp=a[i]-'0'; 
		else if (d==3) tmp=b[i]-'0'; 
		else { if (over) c[i]='1'; break; }

		if (over) { tmp++; over=0;}
		if (tmp/10) over=1;
		c[i]=tmp%10+'0';
	}
	for (int i=0; i<200; i++) printf(i!=199?"%c":"%c\n", c[i]); 
}
