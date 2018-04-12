#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int mn;
int main(){
	int T; scanf("%d", &T);

	for (int t=1; t<=T; t++){

		int cost[4], a[13], d[14], paylen[4]={1, 1, 3, 12};
		memset(d, 0x3f, sizeof(d);						//each memory byte set "0x3f" byte -> 1billions
		for (int i=0; i<4; i++) scanf("%d", &cost[i]);
		for (int i=1; i<=12; i++) scanf("%d", &a[i]);

		d[0]=0;														//start
		for (int i=1; i<=12; i++){
			for (int j=0; j<4; j++){

				if ( i-paylen[j]>=0){ // if we can check d[i-paylen[j]] 
					if(j) d[i]=min(d[i-paylen[j]]+cost[j], d[i]); // if j' is month pay
					else{																					// if j is day pay	
					 	d[i] =min(d[i-paylen[j]]+a[i]*cost[j], d[i]);
					}
				}
				else d[i]=min(cost[j], d[i]); //even we can't check d[i-paylen[j]], 
																			//but we can use coupon
			}
		}
		printf("#%d %d\n", t, d[12]);
	}
}
