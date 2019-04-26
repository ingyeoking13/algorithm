#include <iostream>

using namespace std;

int main(){

  int n;
  cin >>n;

  long long ans =0;
  while (n>=10)
  {
    n++;
    ans++;
    while (n%10 == 0 ) n/=10;
  }
  ans += 10;
  ans--;

  cout << ans << "\n";


}
