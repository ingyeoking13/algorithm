#include <stdio.h>
#include <math.h>

int top();
int mid();
int bot();
int byul(int row);

int main(){
  
  int k, row;
  scanf("%d", &k);
  row=3*pow(2,k);
     
  byul(row); 

  return 0;
}

int byul(int row){
  int i,j,jump;
  for (i=row;i>0;i--){
    for (j=0; j<i; j++){
      printf(" ");
    }
    if(i%3==0) top();
    else if (i%3==2) mid();
    else jump=bot();
  }
}

int top(){
  printf("*\n");
}

int mid(){
  printf("* *\n");
}

int bot(){
	int jump;
  printf("*****\n");
	jump=5;
	return jump;
}

