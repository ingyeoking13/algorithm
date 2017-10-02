#include <cstdio>
#include <queue>
using namespace std;

int main(){

	queue<int> que;
	char input[50];
	int num, tmp;

	scanf("%d", &num);
	while(num--){

		scanf("%s", input);

		if(input[1]=='u'){
			scanf("%d", &tmp);
			que.push(tmp);
		}
		else{
			if(input[0]=='p'){
				if(que.empty()) printf("-1\n");
				else {
					printf("%d\n", que.front());
					que.pop();
				}
			}
			else if(input[0]=='s')
				printf("%d\n", (int)que.size());
			else if(input[0]=='e'){
				if(que.empty()) printf("1\n");
				else printf("0\n");
			}
			else if(input[0]=='f'){
				if(que.empty()) printf("-1\n");
				else printf("%d\n", (int)que.front());

			}
			else if(input[0]=='b'){
				if(que.empty()) printf("-1\n");
				else printf("%d\n", (int)que.back());
			}
		}
	}

	return 0;
}
