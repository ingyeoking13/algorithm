#include <bits/stdc++.h>

int a[6] = {1, 2, 3, 3, 4, 10};
int b[7] = {1, 2, 2, 2, 3, 5, 10};
int main(){
	int T; scanf("%d", &T);
	for (int t_case = 1; t_case <= T; t_case++){

		int tmp, sum=0, sum2=0;;
		for (int i=0; i<6; i++){
			scanf("%d", &tmp);
			sum+=a[i]*tmp;
		}

		for (int i=0; i<7; i++){
			scanf("%d", &tmp);
			sum2+=b[i]*tmp;
		}

		printf("Battle %d: ", t_case);
		if (sum > sum2) printf("Good triumphs over Evil\n");
		else if (sum < sum2) printf("Evil eradicates all trace of Good\n");
		else printf("No victor on this battle field\n");
	}

}
