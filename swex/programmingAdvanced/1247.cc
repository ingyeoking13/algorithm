#include <iostream>
#include <algorithm>
using namespace std;

struct point
{
  int x, y;
  point() {};
  bool operator < ( point b)
  {
    if ( x== b.x ) return y< b.y;
    return x< b.x;
  }
};

bool permutation(int* a, int n)
{
  int i= n-1;
  while ( a[i-1] >= a[i] && i > 0 ) i--;
  if ( i == 0)  return false;
  int j = n-1;
  while ( a[j] <= a[i-1] ) j--;

  int tmp = a[j];
  a[j] = a[i-1];
  a[i-1] = tmp;


  j= n-1;
  while ( i<= j)
  {
    int tmp = a[j];
    a[j] = a[i];
    a[i] = tmp;
    i++, j--;
  }
  return true;
}

int main()
{
  int T;
  int tt=0;
  cin >> T;
  while (++tt <= T)
  {
    int n; 
    cin >> n;
    int ans = 2e9;

    point home, work;
    point a[10];
    int b[10];

    cin >> work.x >> work.y;
    cin >> home.x >> home.y;

    for (int i=0; i<n; i++) 
    {
      cin >> a[i].x >> a[i].y;
      b[i] = i;
    }

    do
    {
      int cost = abs(work.x - a[b[0]].x) + abs(work.y - a[b[0]].y);
      for (int i=0; i<n-1; i++)
      {
        int j = b[i], k = b[i+1];
        cost += abs(a[j].x  - a[k].x) + abs(a[j].y - a[k].y);
      }
      cost += abs(a[b[n-1]].x - home.x) + abs(a[b[n-1]].y - home.y);

      if ( cost < ans ) ans = cost;
    }
    while(permutation(b, n));

    cout << "#" << tt << " " << ans << "\n";
  }
}
