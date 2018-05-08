#include <stdio.h>
int a[2], p[2];
int main(){
	int x, y, z;
	scanf("%d %d %d",&x, &y, &z);
	a[x]++, a[y]++, a[z]++;
	p[a[x]]=0, p[a[y]]=1, p[a[z]]=2;

	if (a[0] ==3 || a[1] == 3) printf("*\n");
	else {
		for (int i=0; i<2; i++) 
			if(a[i] == 1) printf("%c\n", 'A'+p[a[i]]);
	}
}
