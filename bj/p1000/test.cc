#include <iostream>

using namespace std;

long long ans[10];

void calc(long long n, long long ten) {
  while (n > 0) {
    ans[n % 10] += ten;
    n = n / 10;
  }
}

int main() {

  long long start = 0;
  long long end;
  long long ten = 1;
  cin >> end;

  while (start <= end) {

    while (end % 10 != 9 && start <= end) 
    {
      calc(end, ten);
      end -= 1;
    }

    if (start > end) break;

    while (start % 10 != 0 && start <= end) 
    {
      calc(start, ten);
      start += 1;
    }

    start = start / 10;
    end = end / 10;

    long long cnt = (end - start + 1);
    for (int i = 0; i <= 9; i++) 
    {
      ans[i] += cnt*ten;
    }

    ten = ten * 10LL;
  }

for (int i = 0; i <= 9; i++) {
cout << ans[i] << ' ';
}
cout << '\n';
return 0;
}
