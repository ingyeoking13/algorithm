#include <bits/stdc++.h>

using namespace std;
int a[100];
int main(){
	int T; scanf("%d", &T);

	for (int t_case=1; t_case<=T; t_case++){
		int n; scanf("%d", &n);
		int min=101, max=0;
		for (int i=0; i<n; i++){
		 	scanf("%d", &a[i]);
			if (min > a[i]) min=a[i];
			if (max < a[i]) max= a[i];
		}
		sort(a, a+n);
		int gap=0;
		for (int i=1; i<n; i++){
			if (gap < a[i]-a[i-1]) gap = a[i]-a[i-1];
		}
		printf("Class %d\n", t_case);
		printf("Max %d, Min %d, Largest gap %d\n", max, min, gap);
	}

}
