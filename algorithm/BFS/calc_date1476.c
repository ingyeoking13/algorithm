#include <stdio.h>
int main(){
	int e, s, m, i;
	scanf("%d %d %d", &e, &s, &m);
	for (i=1; ;i++)
		if (((i%15?i%15:15)==e)&&((i%28?i%28:28)==s)&&((i%19?i%19:19)==m))
			break;
	printf("%d\n", i);
}
