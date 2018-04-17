#include <stdio.h>
#include <string.h>

using namespace std;
char s[100][10001];
int main(){
	int T; scanf("%d", &T);

	while(T--){

		int n; scanf("%d", &n);
		for (int i=0; i<n; i++) scanf("%s", s[i]);

		char tmp[10001], tmp2[10001], chk=0;
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				if (i == j) continue;
				chk=0;

				int ln1 = strlen(s[i]), ln2= strlen(s[j]);

				int k;
				for (k=0; k<ln1; k++)	 tmp[k]=s[i][k];
				for (; k<ln1+ln2; k++) tmp[k]=s[j][k-ln1];
				tmp[k]=0;

				for (k=0; k<ln2; k++)  tmp2[k]=s[j][ln2-k-1];
				for (; k<ln1+ln2; k++) tmp2[k]=s[i][ln1-(k+1-ln2)];
				tmp2[k]=0;

				if ( strcmp(tmp, tmp2)==0) chk=1;

				if (chk) {
					printf("%s\n", tmp);
					break;
				}
			}
			if (chk) break;
		}
		if (!chk) printf("0\n");
	}
}
