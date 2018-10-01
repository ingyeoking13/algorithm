#include <cstdio>
#define MOD 1003001

using namespace std;

/*
* Time complexity: TODO
* Space complexity: TODO
*/
long long dfs(long long a, long long b){
	if ( a< b)  return 0;
	if ( b== 1) return a;
	if ( b== 0) return 1;
	return dfs(a-1, b-1)%MOD + dfs(a-1, b)%MOD;
}
int main(int argc, const char *argv[]) {
	int T;
	scanf("%d\n", &T);

	for (int i = 0; i < T; i++) {
		long long n, k, m;
		scanf("%lld %lld %lld", &n, &k, &m);
		printf("%lld\n", (dfs(n, m)%MOD*dfs(n, k-m)%MOD)%MOD);
	}

	return 0;
}

