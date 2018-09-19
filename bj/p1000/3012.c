#include <stdio.h>
#include <string.h>

char s[201]; int d[200][200], over=0;
char open[4] = "({[", close[4] = ")}]";

long long mod(long long a){
	if (a>=100000) return 100000+a%100000;
	return a;
}
long long dfs(int f, int t){
	if (f>t) return 1;
	if (d[f][t]>=0) return d[f][t]; 

	d[f][t]=0;
	for (int k=f+1; k<=t; k+=2){
		for (int l=0; l<3;l++){
			if (s[f] ==open[l] || s[f]=='?'){
				if (s[k] == close[l] || s[k]=='?'){
					long long tmp = dfs(f+1, k-1) * dfs(k+1, t);
					d[f][t] += tmp;
					if (d[f][t]>=100000) over=1;
					d[f][t] %= 1000000;
				}
			}
		}
	}
	return d[f][t];
}
int main(){
	int n; scanf("%d", &n);
	scanf("%s", s);
	memset(d, -1, sizeof(d));
	long long ans=dfs(0, n-1);
	printf(over?"%05lld\n":"%lld\n", ans);
}
