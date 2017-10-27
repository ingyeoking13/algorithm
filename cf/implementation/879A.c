#include <stdio.h>

int a, b;
int main(){

	int n, t=0; scanf("%d", &n);
	for (int i=0; i<n; i++){
	 	scanf("%d %d", &a, &b);
		if (t<a) t=a;
		else{
			while(t>=a) a+=b;
			t=a;
		}
	}
	printf("%d\n", t);
}
