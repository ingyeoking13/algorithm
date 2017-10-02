#include <stdio.h>
int main(){
	int n, count=0, ball[200001]={0};
	scanf("%d", &n);
	while(scanf("%d",&n)!=EOF){
		ball[n]^=n;
		if(ball[n]==0)
			break;
		count ++;
	}
	printf("%d\n", count);
}
