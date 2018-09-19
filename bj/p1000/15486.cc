#include <stdio.h>

char days[(int)15e5];
int value[(int)15e5];
int dp[(int)15e5];
int go(int i, int value)
{

}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d %d", &days[i], &value[i]);
    }
    printf("%d\n", go(0, 0));
}