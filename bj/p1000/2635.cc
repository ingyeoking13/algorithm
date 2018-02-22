#include <cstdio>

int findlen(int now, int second, int type){
	int ret=0;
	if (type) printf("%d ", now);

	while(now>=0){
		if(type && second>=0) printf("%d ", second);
		now-=second;

		int tmp= now;
		now= second;
		second = tmp;

		ret++;
	}
	return ret;
}

int main(){
	int n; scanf("%d", &n);
	int max=-1, ans;

	for (int i=1; i<=n; i++){
		if (max< findlen(n, i,0)){
			max= findlen(n, i, 0);
			ans= i;
		}
	}
	printf("%d\n",max);
	findlen(n, ans, 1);
	printf("\n");
}
