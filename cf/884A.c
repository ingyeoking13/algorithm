#include <stdio.h>

int time[100];
int main(){
	int n, t;
	scanf("%d %d", &n, &t);
	for (int i=0; i<n; i++) scanf("%d", &time[i]), time[i]=86400-time[i];
	
	int i=0;
	if (t){
		for (i=0; i<n; i++){
			t-=time[i];
			if (t<=0) break; 
		}
		printf("%d\n",i+1);
	}else printf("0\n");
}
