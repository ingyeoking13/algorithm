#include <stdio.h>
#include <string.h>

char s[15][51];
int a[15], b[51], len[15]; 
long long d[1<<15][100];
long long gcd( long long a, long long b){ return b?gcd(b, a%b):a; }

int main(){
	int n; scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%s", s[i]);
	int k; scanf("%d", &k);

	for (int i=0; i<n; i++) len[i]=strlen(s[i]);

	for (int i=0; i<n; i++){
		for (int j=0; j<len[i]; j++){
			a[i]=a[i]*10+s[i][j]-'0';
			a[i]%=k;
		}
	}

	b[0]=1;
	for (int i=1; i<=50; i++){
		b[i]=b[i-1]*10;
		b[i]%=k;
	}

	d[0][0]=1;
	for (int i=0; i<(1<<n); i++){
		for (int j=0; j<k; j++){
			for (int l=0; l<n; l++){
				if (!(i&(1<<l))){
					int next = j* b[len[l]];
					next %= k;
					next += a[l];
					next %= k;
					d[i|(1<<l)][next] += d[i][j];
				}
			}
		}
	}

	long long t1 = d[(1<<n)-1][0];
	long long t2 = 1;
	for (int i=2; i<=n; i++){
		t2 = t2*i;
	}
	long long g= gcd (t2, t1);
	t1 /=g, t2/=g;
	printf("%lld/%lld\n", t1, t2);
}
