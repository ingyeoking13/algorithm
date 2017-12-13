#include <stdio.h>

int main(){
	int n, m; scanf("%d %d", &n, &m);
	char s[101];
	scanf("%s", s);

	while(m--){
		int l, r; char s2[4];
		scanf("%d %d ", &l, &r);
		fgets(s2, 4, stdin);

		for (int i=l-1; i<r; i++)
			if (s[i]==s2[0]) s[i]=s2[2];
	}
	printf("%s\n", s);
}
