#include <stdio.h>
#include <string.h>
#include <deque>

using namespace std;

int main(){
	deque<int> d;
	int T;
	scanf("%d", &T);
	while(T--){
		char str[50]; int n;
		scanf("%s", str);
		if (!strcmp(str,"push_front")){
			scanf("%d", &n);
			d.push_front(n);
		}
		else if (!strcmp(str,"push_back")){
			scanf("%d", &n);
			d.push_back(n);
		}
		else if (!strcmp(str,"pop_front")) {
			printf("%d\n", d.empty()?-1:d.front());
			if(!d.empty()) d.pop_front(); 
		}
		else if (!strcmp(str,"pop_back")) {
			printf("%d\n", d.empty()?-1:d.back());
			if(!d.empty()) d.pop_back(); 
		}
		else if (!strcmp(str,"size")) printf("%lu\n", d.size()); 

		else if (!strcmp(str, "empty")) printf("%d\n", d.empty());

		else if (!strcmp(str, "front")) printf("%d\n", d.empty()?-1:d.front()); 

		else if (!strcmp(str, "back")) printf("%d\n", d.empty()?-1:d.back());
	}
}
