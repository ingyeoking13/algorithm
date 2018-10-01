#include <stdio.h>
#include <math.h>

int score[20]={6, 13, 4, 18, 1, 20, 5, 12, 9, 14, 11, 8, 16, 7, 19,
	3, 17, 2, 15, 10};

int main(){
	int T;
	scanf("%d",&T);
	for(int test_case=1; test_case<=T; test_case++){
		int A, B, C, D, E;
		scanf("%d %d %d %d %d", &A, &B, &C, &D, &E);

		int t;
		scanf("%d", &t);

		int a, b, ans=0;
		while(t--){
			scanf("%d %d", &a, &b);
			double angle=atan2(b,a)*180/3.141592;
			angle+=9;
			if (angle<0) angle+=360;
			int i=angle/18;

			if (a*a+b*b<A*A) ans+=50;
			else if(a*a+b*b<B*B) ans+=score[i];
			else if(a*a+b*b<C*C) ans+=score[i]*3;
			else if(a*a+b*b<D*D) ans+=score[i];
			else if(a*a+b*b<E*E) ans+=score[i]*2;
		}

		printf("Case #%d\n%d\n",test_case, ans);
	}
}
