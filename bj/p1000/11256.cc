#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  int T;
  scanf("%d", &T);

  while(T--)
  {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> box;

    while(k--)
    {
      int r, c;
      scanf("%d%d", &r, &c);
      box.push_back(-(r*c));
    }

    sort(box.begin(), box.end());

    int ans=0;
    int i=0;
    while(n>0)
    {
      n+=box[i++];
      ans++;
    }
    printf("%d\n", ans);
  }
}
