#include <bits/stdc++.h>

using namespace std;
typedef struct {int w, h;}peo;
peo a[50];
int c[50];

int main(){
	int n; scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%d %d",&a[i].w, &a[i].h);
	}

	for (int i=0; i<n; i++){

		int cnt=1;
		for (int j=0; j<n; j++){
			if (  a[i].h < a[j].h && a[i].w < a[j].w ){
				cnt++;
			}
		}
		c[i]=cnt;

	}

	for (int i=0; i<n; i++){
		printf("%d ", c[i]);
	}
	printf("\n");
}
