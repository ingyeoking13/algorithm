#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
int a[1001];
int main() {
	int n; scanf("%d", &n);
	for (int i=0; i<n; i++) 
	{
		scanf("%d", &a[i]);
	}
	sort(a, a+n);

	int c =0;
	for (int i=0; i<n; i++)
	{
		if ( c+1< a[i]) break;
		c+=a[i];
	}

	printf("%d\n", c+1);
}
