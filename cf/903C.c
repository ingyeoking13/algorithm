#include <stdio.h>

int t, a[5000], b[5000];
int main(){
	int n; scanf("%d", &n);

	for (int i=0; i<n; i++){
		int tmp;
		scanf("%d", &tmp);
		int chk=1;
		for (int j=0; j<t; j++){
			if (a[j]==tmp) chk=0, b[j]++;
		}
		if (chk) a[t]=tmp, b[t++]=1; 
	}

	int max=0;
	for (int i=0; i<t; i++) if(max<b[i]) max=b[i];
	printf("%d\n", max);

}
