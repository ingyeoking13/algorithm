#include <stdio.h>

int a[101], b[101];
int main(){
	int n; scanf("%d", &n);
	for (int i=0; i<2*n; i++) scanf("%d", &a[i]);

	for (int i=0; i<2*n; i++){
		for (int j=0; j<2*n; j++){
			for (int k=0; k<2*n; k++){
				if (k!=j && k!=i) b[k]=a[k];

			}
		}
	}


}
