#include <stdio.h>
#include <string.h>

using namespace std;
int main(){
	char a[1000002];
	scanf("%s", a);
	int n=strlen(a);
	if (n == 1){
	 	printf("0\n");
		if (a[0]=='0') printf("NO\n");
		else if((a[0]-'0')%3==0) printf("OK\n");
		else printf("NO\n");
		return 1;
	}

	int num=0, cnt=1;
	for (int i=0; i<n; i++) num+=(a[i]-'0');

	while(num/10){
		cnt++;
		int now = 0;
		while(num){
			now+=(num%10);
			num/=10;
		}
		num=now;
	}

	if ( num%3 == 0 ) printf("%d\nOK\n",cnt);
	else printf("%d\nNO\n",cnt);

}
