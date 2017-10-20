#include <stdio.h>
#include <string.h>

int main(){

	int t_case, set=0, ans;
	char input[10];
	int inp2;

	scanf("%d", &t_case);
	while (t_case--){
		scanf("%s", input);
		if (!strcmp(input, "add")) { 
			scanf("%d", &inp2); 
			set |= 1<<(inp2-1); 
		} 

		else if (!strcmp(input, "remove")) { 
			scanf("%d", &inp2); 	
			set &= ~(1<<(inp2-1)); 
		}

		else if (!strcmp(input, "check")) { 
			scanf("%d", &inp2);	
			ans = set & 1<<(inp2-1);
			if (ans) printf("1\n"); else printf("0\n");
		}

		else if (!strcmp(input, "toggle")) {
			scanf("%d", &inp2); 
			set ^= 1<<(inp2-1); 
		} 

		else if (!strcmp(input, "all"))
			set = (1<<20) -1;
			
		
		else if (!strcmp(input, "empty"))
			set = 0;
	}


}
