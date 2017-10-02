#include <stdio.h>

int main(){

	int x1, y1, x2, y2;
	int x, y, r, i, orbit;
	int T, testcase, Answer;

	scanf("%d", &testcase);

	for(T=0; T< testcase; T++){
		Answer=0;
	  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		scanf("%d", &orbit);
		for (i=0;i<orbit;i++){
			scanf("%d %d %d", &x, &y, &r);
			if (((x1-x)*(x1-x)+(y1-y)*(y1-y)<r*r)^((x2-x)*(x2-x)+(y2-y)*(y2-y)<r*r))
				Answer++;
		}

		printf("%d\n", Answer);
	}

	return 0;
}
