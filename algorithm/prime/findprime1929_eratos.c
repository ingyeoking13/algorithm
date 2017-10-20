#include <stdio.h>

int main(){

int m, n, i, j;
int arr[1000001]={1};
scanf("%d %d", &m, &n);

for (i=2;i*i<=n;i++){
	if(!arr[i]){
		for(j=i+i;j<=n;j+=i){
			arr[j]=1;
	 	}
	}
}

for (i=m;i<=n;i++)
if(!arr[i]) printf("%d\n", i);

return 0;
}
