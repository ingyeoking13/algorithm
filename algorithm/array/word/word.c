#include <stdio.h>

int main(){
  char word[2000000];
  int i;
  int	count=0;
  int j=0;

  fgets(word, sizeof(word),stdin);
  for (i=0;word[i]!='\n';i++){
		if (word[i]==' ') j=0;
		else {
			if (j==0){ 
				count++;
			  j=1;
			}
		}
  }	

  printf("%d\n",count);	
  return 0;
}
