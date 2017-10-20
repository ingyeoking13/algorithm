#include <stdio.h>
#include <math.h>

int main(){

	int m, n, i, j=0, chk, ans[2000]={0};
	scanf("%d %d", &m, &n);
	m--;

	while(++m<=n){
		chk=0;
		int range=(int)sqrt((double)m);
		if (m == 1) continue;
		else if (m == 2) {ans[j]=m; j++;}
		else if (m%2 == 0) continue;
		else {
			for (i=3;i<=range;i++)
				if(m%i==0) {chk=1;}
			if (!chk) {ans[j]=m; j++;}
		}
	}

	for (i=0; i<j; i++) 
		ans[j]+=ans[i];

	if (ans[0]==0) printf("-1\n");
	else {
		printf("%d\n", ans[j]);
		printf("%d\n", ans[0]);
	}

	return 0;
}
