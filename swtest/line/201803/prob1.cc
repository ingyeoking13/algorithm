#include <cstdio>
#include <string.h>
using namespace std;
/*
 * Time complexity: O(N)
 * Space complexity: O(N)
 */
int main(int argc, const char *argv[]) {
    int T;
    scanf("%d\n", &T);

    for (int i = 0; i < T; ++i) {
      char buf[BUFSIZ];
      scanf("%s\n", buf);
			
			int n = strlen(buf);
			char st = buf[0]; int len=1;
			for (int j=1; j<n; j++){
				if ( st == buf[j] ) len++;
				else {
					printf("%d%c",len,st);
					st=buf[j];
					len=1;
				}
			}
			printf("%d%c\n",len,st);
    }

    return 0;
}

