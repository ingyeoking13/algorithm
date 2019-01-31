#include <stdio.h>
#include <algorithm>

using namespace std;

pair<int, int> array[(int)1e2];
bool myfunc(pair<int, int> a, pair<int, int> b)
{
  if ( a.first == b.first ) return a.second<b.second;
  return a.first < b.first;
}

int main()
{
  int n, a, b;
  scanf("%d%d%d", &n, &a, &b);
  for (int i=0; i<n; i++)
  {
    scanf("%d%d", &array[i].first, &array[i].second);
  }

  sort(array, array+n, myfunc);

  for (int i=0; i<n; i++)
  {

  }


}
