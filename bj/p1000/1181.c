#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[20001][51];
int mycmp(const void* a, const void* b){
	int len= strlen((char *)a)-strlen((char *)b);
	return len?len:strcmp((char *) a, (char *)b);
}
int main(){

	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%s", s[i]);

	qsort(s, n, 51, mycmp);
	printf("%s\n", s[0]);
	for (int i=1; i<n; i++) {
		if (strcmp(s[i],s[i-1])) printf("%s\n", s[i]);
	}
}
