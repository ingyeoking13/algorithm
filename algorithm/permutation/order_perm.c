#include <stdio.h>

int main() {

int N, prob, arr[20];
long long int k;
long long int facto[21] = { 1 };
int i, j, c[21];

for (i = 0; i < 21; i++) c[i] = 0;
for (i = 1; i < 21; i++) facto[i] = facto[i - 1] * i;

scanf("%d", &N);
scanf("%d", &prob);

if (prob == 1) {
	scanf("%lli", &k);
	for (i = 0; i < N; i++) {
		for (j = 1; j <= N; j++) {
			if (c[j] == 1) continue;
			if (facto[N - 1 - i] < k)
				k -= facto[N - i - 1];
			else {
				arr[i] = j;
				c[j] = 1;
				break;
			}
		}
	}

	for (i = 0; i < N; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

else {
	k = 0;

	for (i = 0; i < N; i++) scanf("%d", &arr[i]);
	for (i = 0; i < N; i++) {
		for (j = 1; j < arr[i]; j++)
			if (c[j] == 0)
				k += facto[N - i - 1];

		c[arr[i]] = 1;
	}

	printf("%lli\n", k+1);
}

return 0;
}

