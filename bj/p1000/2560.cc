#include <iostream>
#include <algorithm>
#define MOD 1000

using namespace std;

long long x[(int)1e6+1], y[(int)1e6+1];
// x[i] : i 번째 날 생식 활동을 시작하는 개체의 수  - 끝내는 개체의 수 
// y[i] : i 번째 날 죽는 개체의 수  
long long pred[(int)1e6+1];
int main()
{
  int a, b, d, n;
  cin >> a >> b >> d >> n;

  x[a] = 1;
  x[b] = -1;
  y[d] = 1;

  long long cur =0, cnt =0;
  // cur = 현재 생식 활동 중인 개체의수, cnt = 현재 수조에 살아있는 짚신벌레의 총 개수
  if ( die <= n ) subs++;

  for (int i=0; i<=n; i++)
  {
    cur += x[i];
    cnt = cnt + cur - y[i];
  }

}
