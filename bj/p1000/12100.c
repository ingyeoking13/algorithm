#include <stdio.h>
#include <string.h>

int b[20][20], n, ans;

int max(int x, int y) {return x>y?x:y;}
void back(int turn){

	if (turn == 5) {
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				ans=max(ans, b[i][j]);
			}
		}
		return;
	}

	for (int t=0; t<4; t++){

		int tmp[20][20];
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				tmp[i][j]=b[i][j];
			}
		}

		if (t==0){
			for (int i=0; i<n; i++){ //--->

				for (int j=n-2; j>=0; j--){
					if (b[i][j]){
						while(j+1<n && (!b[i][j+1])) {
							b[i][j+1]=b[i][j];
							b[i][j]=0;
							j++;
						}
					}
				}

				for (int j=n-1; j>=0; j--){
					if (b[i][j] == b[i][j-1]){ 
						b[i][j] *= 2;
						b[i][j-1] = 0;
					}
				}

				for (int j=n-2; j>=0; j--){
					if (b[i][j]){
						while(j+1<n && (!b[i][j+1])) {
							b[i][j+1]=b[i][j];
							b[i][j]=0;
							j++;
						}
					}
				}

			}
		}
		else if (t==1){
			for (int i=0; i<n; i++){ //<---

				for (int j=1; j<n; j++){
					if (b[i][j]){
						while(j>0 && (!b[i][j-1])){
							b[i][j-1]=b[i][j];
							b[i][j]=0;
							j--;
						}
					}
				}

				for (int j=0; j+1<n; j++){
					if (b[i][j] == b[i][j+1]){
						b[i][j]*=2;
						b[i][j+1]=0;
					}
				}

				for (int j=1; j<n; j++){
					if (b[i][j]){
						while(j>0 && (!b[i][j-1])){
							b[i][j-1]=b[i][j];
							b[i][j]=0;
							j--;
						}
					}
				}

			}
		}
		else if (t==2){ // ^^^^^
			for (int j=0; j<n; j++){ 

				for (int i=1; i<n; i++){
					if (b[i][j]){
						while (i>0 && (!b[i-1][j])){
							b[i-1][j]=b[i][j];
							b[i][j]=0;
							i--;
						}
					}
				}

				for (int i=0; i+1<n; i++){
					if (b[i][j] ==b[i+1][j]){
						b[i][j]*=2;
						b[i+1][j]=0;
					}
				}

				for (int i=1; i<n; i++){
					if (b[i][j]){
						while (i>0 && (!b[i-1][j])){
							b[i-1][j]=b[i][j];
							b[i][j]=0;
							i--;
						}
					}
				}

			}
		}
		else { // vvvvvvv
			for (int j=0; j<n; j++){

				for (int i=n-2; i>=0; i--){
					if (b[i][j]){
						while (i+1<n && (!b[i+1][j])){
							b[i+1][j]=b[i][j];
							b[i][j]=0;
							i++;
						}
					}
				}

				for (int i=n-1; i>0; i--){
					if ( b[i][j] == b[i-1][j] ){
						b[i][j]*=2;
						b[i-1][j]=0;
					}
				}

				for (int i=n-2; i>=0; i--){
					if (b[i][j]){
						while (i+1<n && (!b[i+1][j])){
							b[i+1][j]=b[i][j];
							b[i][j]=0;
							i++;
						}
					}
				}

			}
		}


		/*
		printf("\n");
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				printf("%d ", b[i][j]);
			}
			printf("\n");
		}
		*/

		back(turn+1);

		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				b[i][j]=tmp[i][j];
			}
		}
	}
}

int main(){
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			scanf("%d", &b[i][j]);
		}
	}

	back(0);
	printf("%d\n", ans);
}
