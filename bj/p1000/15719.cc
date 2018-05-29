#include <stdio.h>

char a[10000001], b[80000001];

int getdigit(){
	static int i=0;
	int ret = 0;

	while( b[i] >='0'){
		ret*=10;
		ret += b[i]-'0';
		i++;
	}
	i++;
	return ret;
}

int main(){
	fread(b, 1, sizeof(b), stdin);
	int n= getdigit();

	for (int i=0; i<n; i++){
		int tmp= getdigit();
		a[tmp]++;
	}

	for (int i=0; i<=10000000; i++){
		if ( a[i]==2) {
			return !printf("%d\n", i);
		}
	}
}
