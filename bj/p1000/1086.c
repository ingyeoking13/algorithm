#include <stdio.h>

char s[15][51];
int a[15], b[51];
long long gcd( long long a, long long b){ return b?gcd(b, a%b):a; }

int main(){
	int n; scanf("%d", &n);
	for (int i=0; i<n; i++) scanf(" %s", s[i]);
	int k; scanf("%d", &k);

	for (int i=0; i<n; i++){
		for (int j=0; s[j]; j++){
			a[i]=a[i]*10+s[i][j]-'0';
			a[i]%=k;
		}
	}

	b[0]=1;
	for (int i=1; i<=50; i++){
		b[i]=b[i-1]*10;
		b[i]%=k;
	}

}
