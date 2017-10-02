#include <cstdio>
#include <algorithm>

int main(){

	int i, scale;
	int arr[10000];

	scanf("%d", &scale);
	for (i=0; i<10000; i++) arr[i]=0;
	for (i=0; i<scale; i++) scanf("%d", &arr[i]);

	if(std::next_permutation(arr,arr+scale))
		for(i=0;i<scale;i++)
			printf("%d ", arr[i]);
	else printf("-1");
	
	printf("\n");
	
	return 0;

}
