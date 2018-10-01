#include <cstdio>
#include <algorithm>

int main(){

	int city, cost[10][10], ok;
	int perm[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int i, j, tmp, ans=2147483647;

	scanf("%d", &city);

	for (i=0; i<city; i++)
		for (j=0; j<city; j++)
			scanf("%d", &cost[i][j]);

	do{
		if (perm[0]==1){
			tmp=0; ok=1;
			for (i=0;i<city-1;i++){
				tmp+=cost[perm[i]][perm[i+1]];
				if (!cost[perm[i]][perm[i+1]]) ok=0;
			}
			if (!cost[perm[city-1]][perm[0]]) ok=0;
			tmp+=cost[perm[city-1]][perm[0]];
			if (ok && tmp<ans) ans=tmp;
		}
	}while(std::next_permutation(perm, perm+city));

	printf("%d\n", ans);
	return 0;
}
