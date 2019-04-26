#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct data
{
  int key, next, idx, prev;
  data()
  {
  }
  bool operator<(data nxt) { return key < nxt.key; };
}

data a[(int)2e5];
int ans[(int)2e5];
int m[(int)2e5+1];

int main()
{
  int n, k;
  cin >> n >> k;
  for (int i=0; i<n; i++)
  {
    cin >> a[i].key; a[i].idx = i;
  }

  for (int i=0; i<n; i++)
  {
    if ( i-1 >=0) a[i].prev = a[i-1].key;
    if ( i+1 <n ) a[i].next = a[i+1].key;
  }

  sort(a, a+n);

  for (int i=0; i<n; i++)
  {
    m[a[i].key] = i;
  }

  for (int i=0; i<n; i++)
  {
    int cur = i;
    for (int l=0; l<k; l++)
    {
      int nxtkey = m[a[cur].next];
    }

    int team;
    if (i%2 == 0) team=1;
    else team =2;

  }

  for (int i=0; i<n; i++) cout << ans[i];

}
