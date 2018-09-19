#include <stdio.h>
#include <math.h>

int chk(int n){ int a=sqrt(n); return a*a==n; }
int main(){

	int n;
	scanf("%d", &n);
	int ans;
	if(chk(n)) ans=1; 

}
