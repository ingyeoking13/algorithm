#include <stdio.h>

int a[2001], b[2001];
int chk[2500000];
int main(){
	int n; long long ans=0;
	scanf("%d", &n);

	for (int i=0; i<n; i++) {
		scanf("%d", &a[i]);
		chk[a[i]]=1;
	}
	for (int i=0; i<n; i++){
	 	scanf("%d", &b[i]);
		chk[b[i]]=1;
	}

	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			if (chk[a[i]^b[j]]) ans++;
		}
	}

	if (!(ans%2)) printf("Karen\n");
	else printf("Koyomi\n");
}
