#include <stdio.h>

long long a[2000];
int main(){
	int n, ans=0, t=0;
	scanf("%d", &n);

	if (n<1023){
		long long now, i;
		for (now=1,i=1; i<=n;){
			long long j=now, jump=1;
			int before=-1, chk=1;
			while(j){
				if(j%10<=before) chk=0;
				before=j%10; 
				j/=10;
				if (!chk && j%10>=before) continue;
				if (j/10) jump*=10;
			}
			if (chk) { a[i++]=now++;}
			else {
				now+=jump;
				now=now/jump*jump;
			}
		}

		printf("%lld\n", a[n]);
	}
	else printf("-1\n");
}
