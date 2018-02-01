#include <stdio.h>
#include <stdlib.h>

static int cnt = 0;
long long fibo(int n);

int main()
{
    fibo(25); //163578 회 호출
    for(;;);
    return 0;
}



long long fibo(int n)
{
    cnt++;
    printf("%d\n", cnt);
    if(n <= 2)
        return 1;
    else
        return fibo(n - 1) + fibo(n - 2);
}


