#include <stdio.h>
int main() {
	int n;
	int i=0;

	printf("Enter any number to print Prime factors : ");
	scanf("%d", &n);
	for (i = 2; i < n; i++) {
		if (n%i == 0) {
			printf("%d %d\n", i, n/i);
		}
	}

	return 0;
}
