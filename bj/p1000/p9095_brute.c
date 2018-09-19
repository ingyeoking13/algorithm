#include <stdio.h>

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int obj, ans=0;
		scanf("%d", &obj);
		for (int i=1; i<=3; i++){
			if (i==obj) ans++;
			for (int j=1; j<=3; j++){
				if (i+j==obj) ans++;
				for (int k=1; k<=3; k++){
					if (i+j+k==obj) ans++;
					for (int l=1; l<=3; l++){
						if (i+j+k+l==obj) ans++;
						for (int m=1; m<=3; m++){
							if (i+j+k+l+m == obj) ans++;
							for (int n=1; n<=3; n++){
								if (i+j+k+l+m+n == obj) ans++;
								for (int o=1; o<=3; o++){
									if (i+j+k+l+m+n+o == obj) ans++;
									for (int p=1; p<=3; p++){
										if (i+j+k+l+m+n+o+p == obj) ans++;
										for (int q=1; q<=3; q++){
											if (i+j+k+l+m+n+o+p+q == obj) ans++;
											for (int r=1; r<=3; r++){
												if (i+j+k+l+m+n+o+p+q+r == obj) ans++;
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
