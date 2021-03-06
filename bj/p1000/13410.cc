/*
백준 13410
거꾸로 구구단 

모든 경우의 수를 다해서 구해낼 수 있습니다.
시간 복잡도는 O ( n * log10(n*k)) 입니다. 
공간 복잡도는 O ( n ) 입니다. 
*/
#include <stdio.h>

int a[1000];
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int len = 0;
    // n 의 1~k 배 를 구합니다.
    // k는 최대 1000이 될 수 있습니다. 문제 조건을 통해 알 수 있습니다.
    for (int i=1; i<=k; i++)
    {
        a[len++] = n*i;
    }

    int ans =0;
    for (int i=0; i<len; i++)
    {
        int val = 0;
        // a[i]의 일의 자리서부터 가져와서 val에 더합니다. 그리고 a[i]를 10으로 나눕니다. 
        // a[i]가 더 있을 경우 val*=10 을 수행하고, a[i]의 1의 자리를 가져와서 val에 더합니다.
        while(a[i] > 0)
        {
            val*=10;
            val+= (a[i]%10);
            a[i]/=10;
        }

        if ( val > ans ) ans = val;
    }
    printf("%d\n", ans );
}