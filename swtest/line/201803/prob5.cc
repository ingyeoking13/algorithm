#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

/*
* Time complexity: TODO
* Space complexity: TODO
*/
struct alba{ int d, in; };
vector<vector<alba> > a(201);
int d[201][101];

int main(int argc, const char *argv[]) {
	int count;
	scanf("%d\n", &count);

	for (int i = 0; i < count; ++i) {
		int s, d, in;
		scanf("%d %d %d", &s, &d, &in);
		a[s].push_back({d, in});
	}

	d[0][0]=1;
	int mx =0;
	vector<pair<int,int> > ans[201][101];
	int pred[201];
	for (int i=0; i<a.size(); i++){

		for (int j=0; j<a[i].size(); j++){
			for (int k=i; k>=0; k--){
				for (int l=0; l<=100; l++){
					if ( d[k][l] ) {
						d[i+a[i][j].d][l+a[i][j].in]=1;
//						printf("i,j,k, a[i][j].d : %d,%d,%d,%d.... %d %d\n",
//								i,j,k,a[i][j].d, i+a[i][j].d, l+a[i][j].in);
						mx = max(mx, l+a[i][j].in);
						ans[i+a[i][j].d][l+a[i][j].in].push_back({a[i][j].in, a[i][j].d});
						pred[i+a[i][j].d]=pred[i];
					}
				}
			}
		}

	}
	printf("%d\n", mx);


	return 0;
}

