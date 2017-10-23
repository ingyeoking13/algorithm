#include <stdio.h>
#include <stdlib.h>
 
int mycmp(const void *a, const void* b) { return *(int *)a - *(int *)b; }
int main(int argc, char *argv[]) {
	//init
	int n;
	scanf("%d", &n);
	int * arr = (int *)malloc(n * sizeof(int));

	//find mean
	double sum = 0;
	for (int i = 0; i < n; i++)  scanf("%d", &arr[i]); 
	for (int i= 0; i < n; i++) sum += arr[i];
	printf("mean: %.2f\n", sum / n);

	//find median
	qsort(arr, n, sizeof(int), mycmp);
	double m2 = (arr[n / 2] + arr[(n / 2) - 1]) / 2.0;
	if (n % 2 == 0)  printf("median: %.2f\n", m2);
	else printf("median: %d\n", arr[n / 2]);
	
	//find mode
	int brr[100000], ans[100000], h=0, t=0;
	for (int i=0; i<100000; i++) brr[i]=0;
	for (int i=0; i < n; i++) brr[arr[i]]++;

	int max=0;
	for (int i=0; i<100000; i++){
		if (brr[i]>max) {
			t=0;
			max=brr[i];
			ans[t++]=i;
		}
		else if (brr[i]==max) ans[t++]=i; 
	}
	
	printf("mode: ");
	while (h<t) printf("%d ", ans[h++]);
	printf("\n");
	
	free(arr);
	return 0;
}
