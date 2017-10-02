#include <stdio.h>

int main(){
	int a, b; double ans;
	scanf("%d %d", &a, &b);
	if (a==b) ans=(double)(153-(10-a))/153;
	else{
		double cnt=0;
		for (int i=1;i<=10; i++){
			for (int j=1;j<=10; j++){
				if (i==j || i==a || i==b) continue;
				if ((i+j)%10<(a+b)%10) cnt+=2; 
			}
		}
		ans=cnt/153;
	}
	printf("%.3lf\n", ans);
}
