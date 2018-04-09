#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cmath>
using namespace std;

/*
 * Time complexity: O(NlogN)
 * Space complexity: O(N)
 */
struct shop{ 
	double x, y; 
	char * name;
	int coupon;
	
	shop(double x, double y, char* s, int c) : x(x), y(y), coupon(c){
		name = new char[BUFSIZ];
		strcpy(name, s);
	}
};

double x, y;

int prec(char a){
	if ( 'A' <= a && a<='Z') return a-'A'+10;
	else return a-'0';
}

bool mycmp(shop& a, shop&b){
	double dist_1 = (a.x-x)*(a.x-x)+(a.y-y)*(a.y-y);
	double dist_2 = (b.x-x)*(b.x-x)+(b.y-y)*(b.y-y);
  int refd1 = sqrt(dist_1)/100;
	int refd2 = sqrt(dist_2)/100;
	
	if ( refd1 != refd2 )	return refd1<refd2;
		else {
		if ( a.coupon != b.coupon) 	return a.coupon > b.coupon;	
		
		int n = strlen(a.name);
		for (int i=0; i<n; i++){
			if ( prec(a.name[i]) != prec(b.name[i]) ){
				return prec(a.name[i]) < prec(b.name[i]);
			}
		}
	}
	return 0;
}

int main(int argc, const char *argv[]) {
    int N;
  
    scanf("%lf %lf %d\n", &x, &y, &N);
		vector<shop> v;
	
    for (int i = 0; i < N; ++i) {
        char name[BUFSIZ];
        double shop_x, shop_y;
        int coupon_count;
        scanf("%lf %lf %s %d\n", &shop_x, &shop_y, name, &coupon_count);
				shop tmp(shop_x,shop_y, name, coupon_count);
				v.push_back(tmp);
    }
	  sort(v.begin(), v.end(), mycmp);
	  for (int i=0; i<N; i++) printf("%.0lf %.0lf %s %d\n", v[i].x, v[i].y, v[i].name, v[i].coupon);
    return 0;
}

