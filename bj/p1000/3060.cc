#include <stdio.h>
#include <string.h>
#define MOD 6

int ret(int a)
{
  if ( a == -1 ) return 5;
  return a%MOD;
}

int main()
{
  int T;
  scanf("%d", &T);
  long long a[6];

  while(T--)
  {
    long long n; scanf("%lld", &n);
    for (int i=0; i<6; i++) scanf("%lld", &a[i]);

    //입력 끝
    //이제 한 턴의 모든 돼지가 원하는 양을 도출하자

    long long sum =0;
    for (int i=0; i<6; i++) sum += a[i];
    int ans =1; // day ellapsed based 1

    while ( sum <= n)
    {
      ans++;
      //이제 모든 a를 업데이트하자.
      long long b[6];

      sum = 0;
      for (int i=0; i<6; i++)
      {
        b[i] = a[i]+a[ret(i-1)] + a[ret(i+1)] + a[ret(i+3)];
        sum += b[i];
      }

      for (int i=0; i<6; i++)
      {
        a[i] = b[i];
      }
    }

    printf("%d\n", ans);
  }
}
