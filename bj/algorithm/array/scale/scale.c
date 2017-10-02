#include <stdio.h>

int main(){
	    
	int scale[8];
	int i, answer;
					    
	answer = 0;

	for (i=0;i<8;i++)
		scanf("%d", &scale[i]);
									    
	for (i=0;i<7;i++){
		if ((scale[i+1]-scale[i])>0) answer++;
		else answer--;
	}

	if (answer==7) printf("ascending\n");	
	else if (answer==-7) printf("descending\n");
	else printf("mixed\n");
											    
											    
}
