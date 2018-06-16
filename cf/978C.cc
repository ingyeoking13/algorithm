#include <stdio.h>
using namespace std;

long long a[200001];
int main(){
	int n,m; scanf("%d %d", &n, &m);
	for (int i=1; i<=n; i++) {
		scanf("%lld" ,&a[i]);
		a[i] += a[i-1];
	}

	int room=1;
	for (int i=0; i<m; i++){
		long long tmp;
		scanf("%lld", &tmp);

		while(a[room]<tmp) room++;
		printf("%d %lld\n", room, tmp-a[room-1]);
	}


}
