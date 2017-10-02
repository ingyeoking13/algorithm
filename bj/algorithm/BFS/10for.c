#include <stdio.h>

int main(){

	int T, testCase;
	int ans, i, input;
	int l1, l2, l3, l4, l5, l6, l7, l8, l9, l0;
  scanf("%d", &testCase);
	for (T=0; T<testCase; T++){
		scanf("%d", &input);
		ans=0;
		for (l1=1; l1<=3;l1++){
			if (l1==input) ans+=1;
			for (l2=1;l2<=3;l2++){
				if (l1+l2==input) ans+=1;
				for (l3=1;l3<=3;l3++){
					if (l1+l2+l3==input) ans+=1;
					for (l4=1;l4<=3;l4++){
						if (l1+l2+l3+l4==input) ans+=1;
						for (l5=1;l5<=3;l5++){
							if (l1+l2+l3+l4+l5==input) ans++;
							for (l6=1;l6<=3;l6++){
								if (l1+l2+l3+l4+l5+l6==input) ans++;
								for(l7=1;l7<=3;l7++){
									if (l1+l2+l3+l4+l5+l6+l7==input) ans++;
									for (l8=1;l8<=3;l8++){
										if (l1+l2+l3+l4+l5+l6+l7+l8==input) ans++;
										for (l9=1;l9<=3;l9++){
											if (l1+l2+l3+l4+l5+l6+l7+l8+l9==input) ans++;
											for (l0=1;l0<=3;l0++){
												if (l1+l2+l3+l4+l5+l6+l7+l8+l9+l0==input) ans++;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}

		printf("%d\n", ans);
	}
}
