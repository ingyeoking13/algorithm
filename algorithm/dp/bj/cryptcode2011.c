#include <stdio.h>
#define mod 1000000

long long a[5001], d[5001];
int main(){
	char ch;
	int i=1;
	while(ch=getchar()) {
		if (ch=='\n' || ch==-1) break;
		a[i++]=ch-'0';
	}

	int len=i;
	d[0]=1;
	for (i=1; i<len; i++){
		if(1<=a[i] && a[i]<=9)
			d[i]= d[i-1]%mod;

		if (i==1) continue;
		if (a[i-1]==0) continue;
		if (10<=a[i-1]*10+a[i] && a[i-1]*10+a[i]<=26){
			d[i]=(d[i]+d[i-2])%mod;
		};
	}
	printf("%lld\n", d[len-1]);

}
