#include <stdio.h>

int arr[10010];
int main(){

	int len=1;
	for (int i=1; i<=100; i++)
		for (int j=0; j<i; j++)
			arr[len++]=i;

	int a, b;
	scanf("%d %d", &a, &b);
	int ans=0;
	for (int i=a; i<=b; i++) ans+=arr[i];
	printf("%d\n", ans);

}
