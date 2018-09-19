#include <stdio.h>

int arr[1000001];

int find(int num){
	if (num==arr[num]) return num;
	else return arr[num]=find(arr[num]);
}

int main(){
int n, T;
scanf("%d %d", &n, &T);

for (int i=1; i<=n; i++) arr[i]=i;

	while(T--){
		int in, a, b;
		scanf("%d", &in);
		if (in){
			scanf("%d %d", &a, &b);
			if (find(a)==find(b)) printf("YES\n");
			else printf("NO\n");
		}
		else{
			scanf("%d %d", &a, &b);
			arr[find(a)]=find(b);
		}
	}
}
