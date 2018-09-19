#include <stdio.h>

char a[101];
void h(int n, int f, int b, int t){
	if (n==1){
		printf("%d %d\n", f, t);
		return;
	}

	h(n-1, f, t, b);
	printf("%d %d\n", f, t);
	h(n-1, b, f, t);
	
};

int main(){
	int n, j; a[100]='1';
	scanf("%d", &n);

	for (int i=0; i<n; i++){
		int s=0;
		for (j=100; a[j]; j--){
			int tmp=s+(a[j]-'0')*2;
			s=tmp/10;
			a[j]=tmp%10+'0';
		}
		if (s) a[j--]='1';
	}

	a[100]-=1;
	puts(a+j+1);

	if(n<21) h(n, 1, 2, 3);
}
