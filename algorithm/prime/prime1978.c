#include <stdio.h>
#include <math.h>

int main(){

	int num, arr[100];
	int i, j, ans=0, chk;

	scanf("%d", &num);

	for(i=0;i<num;i++)
		scanf("%d", &arr[i]);

	while(i--){
		int range =(int)sqrt((double)arr[i]);
		chk=0;

		if (arr[i]==1) continue;
		else if (arr[i]==2) ans++;
		else {
			for (j=2;j<=range;j++) 
				if (arr[i]%j==0) chk=1;
			if (!chk) ans++;
		}
	}

	printf("%d\n", ans);
}
