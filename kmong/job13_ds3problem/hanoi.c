#include <stdio.h>

int pole[4][5];

void print(){
	for (int i=0; i<2; i++){
		printf("|              	   ||                  ||                  |\n");
	}

	for (int i=0; i<=4; i++){

		for (int j=1; j<=3; j++){
			if (i==0 )    printf("|        ");
			else if(i==1) printf("|       ");
			else if(i==2) printf("|      ");
			else if(i==3) printf("|     ");
			else if(i==4) printf("|    ");

			if(pole[j][i]){
				for (int k=0; k<=i; k++) printf("* ");
			}
			else {
				for (int k=0; k<=2*i+1; k++) printf(" ");
			}

			if (i==0 )    printf("        |");
			else if(i==1) printf("       |");
			else if(i==2) printf("      |");
			else if(i==3) printf("     |");
			else if(i==4) printf("    |");
		};
		printf("\n");
	}
	printf("============================================================\n");
}

void move_pan(int f, int t, int n){
	pole[f][n]=0;
	pole[t][n]=1;
	print();
}

void go(int f, int m, int t, int n){
	if ( n==0){
		move_pan(f, t, n);
		return ;
	}

	go(f, t, m, n-1);
	move_pan(f, t, n);
	go(m, f, t, n-1);
}

int main(){
	int n; scanf("%d", &n);
	for (int i=0; i<n; i++) pole[1][i]=1;

	printf("pole1 >> pole2\n\n");
	printf("===========================================================\n");
	printf("|  pole1                  pole2                    pole3  |\n");
	printf("===========================================================\n");
	print();
	go(1, 3, 2, n-1);
	printf("total move : %d\n", (1<<n)-1);

}
