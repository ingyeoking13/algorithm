#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  int n;
  scanf("%d", &n);

  vector<int> idx;
  int mx = -1;
  int a[(int)1e5];
  for (int i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
    if ( a[i] > mx )
    {
      mx = a[i];
      idx.clear();
      idx.push_back(i);
    }
    else if ( a[i] == mx ) idx.push_back(i);
  }

  int sequence=1, prev =idx[0], ans=1;
  for (int i=1; i<idx.size(); i++)
  {
    if ( idx[i] == prev+1 ) sequence++;
    else 
    {
      ans = max(sequence, ans);
      sequence = 1;
    }
    prev = idx[i];
  }
  ans = max(sequence, ans);

  printf("%d\n", ans);
}
