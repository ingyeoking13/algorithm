#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {

	int T; scanf("%d", &T);

	while(T--){
		int n; scanf("%d", &n);
		char f[100002]; scanf("%s", f);
		char t[100002]; scanf("%s", t);

		int cnt=0;
		for (int i=0; i<n; i++)
			if (f[i] != t[i] ) cnt++;

		int tmp=0;
		for (int i=0; i<n; i++)
			if (f[i]!= t[i] && f[i] == 'W' ) tmp++;
		cnt = cnt -tmp;
		// 7 ~ 5 2  =  2, 3
		printf("%d\n",  max(cnt,tmp));
	}
}
