#include <stdio.h>
#include <vector>
using namespace std;

char s[1000000];

int gcd(int a, int b){
	if (b==0) return a;
	else return gcd(b, a%b);
}
int main(){
	int n; scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%s", s+i);
	}
	char s2[3];
	for (int i=0; i<n; i++) scanf("%s", s2);

	vector<int> pi(n);

	pi[0] =0;
	int j=0;
	for (int i=1; i<n; i++){
		while( j>0  && s[i] != s[j] ){
			j = pi[j-1];
		}
		if (s[i] == s[j] ){
			pi[i] = ++j;
		}else{
			pi[i] =0;
		}
	}

	int mo = gcd(pi[n-1], n);
	printf("%d\n", mo);
	printf("%d", pi[n-1]);
	printf("%d / %d \n", pi[n-1]/mo, n/mo);
}
