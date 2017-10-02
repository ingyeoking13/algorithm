#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;

int main(){

	stack<int> stack;
	int num, tmp;
	char input[20];

	scanf("%d", &num);

	while(num--){
		scanf("%s", input);
		if(!strcmp(input,"push")){
			scanf("%d", &tmp); 
			stack.push(tmp);
		}
		else if (!strcmp(input, "pop")){
			if(!stack.empty()){
				printf("%d\n", stack.top());
				stack.pop();
			}
			else printf("-1\n");
		}
		else if (!strcmp(input, "size")){
			printf("%lu\n", stack.size());
		}
		else if(!strcmp(input, "empty")){
			if(stack.empty()) printf("1\n");
			else printf("0\n");
		}
		else if(!strcmp(input, "top")){
			if(stack.empty()) printf("-1\n");
			else printf("%d\n", stack.top());
		}
	}
	return 0;
}
