#include <stdio.h>

int Answer;

int main(void)
{
int T, test_case;
int row, col, obs;    //row, column, obstacle
int arr[100001][100001];
setbuf(stdout, NULL);

scanf("%d", &T);
for(test_case = 0; test_case < T; test_case++)
{

	scanf("%d %d %d", &row, &col, &obs);




	printf("Case #%d\n", test_case+1);
	printf("%d\n", Answer);

}

return 0;//Your program should return 0 on normal termination.
}
