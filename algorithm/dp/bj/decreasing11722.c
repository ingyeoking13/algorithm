#include <stdio.h>
int main(){
	int s[1000], d[1000], n;
	scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", &s[i]);
		
	d[0]=1;
	for (int i=1; i<n; i++){
		d[i]=1;
		for (int j=0; j<i; j++){
			if(s[i]<s[j]) 
				if (d[i]<d[j]+1)
					d[i]=d[j]+1;
		}
	}
	int ans=0;
	for (int i=0; i<n; i++)
		if (ans<d[i]) ans=d[i];
	printf("%d\n", ans);
}
