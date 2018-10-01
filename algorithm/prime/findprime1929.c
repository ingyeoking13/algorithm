#include <stdio.h>

int main(){

	int m, n, i, j;
	scanf("%d %d", &m, &n);

	for (i=m;i<=n;i++){
		int chk=1;
			for(j=2;j*j<=i;j++){
				if(i%j==0) 
				{ chk=0; break;}
			}
			if (chk && i>=2) printf("%d\n", i);
		}

	return 0;
}

