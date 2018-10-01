#include <cstdio>
#include <stack>

using namespace std;
int main(){

	int num[26], i, n;
	char input[100];
	double ans=0;
	stack<double> stack;

	scanf("%d", &n);
	scanf("%s", input);
	for(i=0; i<n; i++) scanf("%d", &num[i]);

	i=0;
	while(input[i]!='\0'){
		if(input[i]-'A'>=0)
			stack.push(num[input[i]-'A']);
		else{
				double temp = stack.top();
				stack.pop();
				double temp2 = stack.top();
				stack.pop();
			if (input[i]=='+'){
				stack.push(temp+temp2);
			}
			else if (input[i]=='*'){
				stack.push(temp*temp2);
			}
			else if (input[i]=='/'){
				stack.push(temp2/temp);
			}
			else if (input[i]='-'){
				stack.push(temp2-temp);
			}
		}
		i++;
	}
	ans = stack.top();
	printf("%.2f\n", ans);
	return 0;
}
