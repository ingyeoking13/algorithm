#include <stdio.h>
#include <stdlib.h>

int a[101], ans=1<<25;
int mycmp(const void *a, const void *b) {
 	return *(int *)b - *(int *)a; }

int main(){
	int n; scanf("%d", &n);
	for (int i=0; i<2*n; i++) scanf("%d", &a[i]);
	qsort(a, 2*n, sizeof(int), mycmp);

	for (int i=0; i<2*n; i++){
		for (int j=i+1; j<2*n; j++){
			int chk=1, tmp=0;
			for (int k=0; k<2*n; k++){
				if (k==j || k==i) continue;
				if (chk) tmp+=a[k], chk=0;
				else tmp-=a[k], chk=1;
			}
			if (ans>tmp) ans=tmp;
		}
	}
	printf("%d\n", ans);
}
