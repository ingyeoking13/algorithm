#include <stdio.h>
typedef struct {int cnt; }num;
num a[4001], b[4001];
int min=4001, max=-4001, maxcnt=0;

int main(){
	int n; scanf("%d", &n);
	double mean=0;
	for (int i=0; i<n; i++){
		int tmp; scanf("%d", &tmp);
		if (tmp>=0) {
			a[tmp].cnt++;
			if ( a[tmp].cnt > maxcnt ) maxcnt = a[tmp].cnt;
		}
		else{ 
			b[-tmp].cnt++;
			if ( b[-tmp].cnt > maxcnt ) maxcnt = b[-tmp].cnt; 
		}
		if (tmp > max) max = tmp;
		if (tmp < min) min = tmp;
		mean+=tmp;
	}
	printf("%.0lf\n", mean/n);

	int cnt=0, chk=0, mid;
	for (int i=4000; i>=0; i--){
		if ( chk ) break;
		for ( int j=0; j<b[i].cnt ; j++){
			if ( cnt == n/2) { chk=1; mid=-i;break; }
			cnt++;
		}	
	}
	for (int i=0; i<=4000; i++){
		if ( chk ) break;
		for ( int j=0; j<a[i].cnt ; j++){
			if ( cnt == n/2) { chk=1; mid=i;break; }
			cnt++;
		}	
	}
	printf("%d\n", mid);

	chk=0;
	int mode=0;
	for (int i=4000; i>=0; i--){
		if (b[i].cnt==maxcnt && chk<2) { chk++; mode = -i; }	
	}
	for (int i=0; i<=4000; i++){
		if (a[i].cnt==maxcnt && chk<2) { chk++; mode = i; }	
	}
	printf("%d\n%d\n", mode,max-min);
}
