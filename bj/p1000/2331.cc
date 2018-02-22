#include <stdio.h>
using namespace std;
int v[240000];

int pow(int n, int p){
	int ret=n;
	while(--p) ret*=n;
	return ret;
}

int calc(int now, int p){
	int ret=0;
	while(now) {
		ret+=pow(now%10, p);
		now/=10;
	}
	
	return ret;
}

int length(int now, int p, int cnt){
	if (v[now]) return v[now]-1;
	v[now]=cnt;
	int next=calc(now, p);
	return length(next, p, cnt+1);
}

int main(){
	int a,p; scanf("%d %d", &a, &p);
	printf("%d\n", length(a, p, 1));
}
