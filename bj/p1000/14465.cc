#include <iostream>

using namespace std;

int n, k, b;
bool broken[(int)1e5];
int main()
{
  cin >> n >> k >> b;
  for (int i=0; i<b; i++)
  {
    int tmp;
    cin >> tmp;
    tmp--;
    broken[tmp] =true;
  }
  int ans = 0;
  for (int i=0; i<k; i++)
  {
    if (broken[i] ) ans++;
  }

  int cost = ans;
  for (int i=1; i+k-1 < n; i++)
  {
    if ( broken[i-1] ) cost--;
    if ( broken[i+k-1] ) cost++; 
    if ( cost < ans ) ans = cost;
  }
  cout << ans <<"\n";

}
