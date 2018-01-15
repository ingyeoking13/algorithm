#include <stdio.h>

int d[21][20][20][20][20], a[20][20];
int main(){
	int n, k; scanf("%d %d", &n, &k);
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			scanf("%d", &a[i][j]);
		}
	}


	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			d[1][i][j][i][j]=1;
		}
	}

	for (int x1=0; x1<n; x1++){
		for (int y1=0; y1<n; y1++){
			for (int x2=x1-1; x2<=x1+1; x2++){
				for (int y2=y1-1; y2<=y1+1; y2++){
					if ( 0<= x2 && x2 <n && 0<= y2 && y2<n){
						if (!(x1==x2 && y1==y2)) {
							d[2][x1][y1][x2][y2]=(a[x1][y1] == a[x2][y2]);
						}
					}
				}
			}
		}
	}

	for (int i=3; i<=k; i++){
		for (int x1=0; x1<n; x1++){
			for (int y1=0; y1<n; y1++){
				for (int x2=0; x2<n; x2++){
					for (int y2=0; y2<n; y2++){
						if (a[x1][y1] == a[x2][y2]){
							for (int x3=x1-1; x3<=x1+1; x3++){
								for (int y3= y1-1; y3<= y1+1; y3++){
									for (int x4=x2-1; x4<= x2+1; x4++){
										for (int y4=y2-1; y4<= y2+1; y4++){
											if (0<= x3 && x3< n && 0 <= y3 && y3 < n){
												if (0<= x4 && x4< n && 0 <= y4 && y4 < n){
													if ( !(x1== x3 && y1 == y3) && !(x2 == x4 && y2==y4)){
														d[i][x1][y1][x2][y2] += d[i-2][x3][y3][x4][y4];
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
			}
		}
	}

	int ans=0;
	for (int x1=0; x1<n; x1++){
		for (int y1=0; y1<n; y1++){
			for (int x2=0; x2<n; x2++){
				for (int y2=0; y2<n; y2++){
					ans += d[k][x1][y1][x2][y2];
				}
			}
		}
	}
	printf("%d\n", ans);
}
