#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>

using namespace std;
int ret(char c){
	if ( 'a' <= c && c<= 'z' ) return c-'a';
	else if ( 'A' <= c && c<= 'Z' ) return c-'A'+26;
}

int main(){
	int n; scanf("%d", &n);
	vector<string> str(3);
	int a[3][52];
	memset(a, 0, sizeof(a));
	vector<int> mx(3, 0);

	char s[100001];
	for (int i=0; i<3; i++){
		scanf("%s",s);
		str[i]=string(s);
	}

	int len = str[0].length();

	for (int i=0; i<3; i++){
		for (int j=0; j<len; j++){
			a[i][ret(str[i][j])]++;
			if ( a[i][ret(str[i][j])] > mx[i] ) {
				mx[i] = a[i][ret(str[i][j])];
			}

		}
	}
	
	int ans=-1, good=0, cnt=0;
	for (int i=0; i<3; i++){
		if ( n- mx[i] >=len ) cnt++;

		if ( mx[i] > good) good=mx[i], ans= i;
	}

	if (cnt>1) return !printf("Draw\n");
	else {
		if ( ans == 0) printf("Kuro\n");
		else if (ans== 1) printf("Shiro\n");
		else printf("Katie\n");
	}

}
