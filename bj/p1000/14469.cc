#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct cow
{
  int arrive, cost;
  cow(int a, int c) : arrive(a), cost(c) {};
  bool operator < ( cow b ) { return arrive < b.arrive; } ;
};

int main()
{

  int n;
  scanf("%d", &n);

  vector<cow> v;
  for (int i=0; i<n; i++)
  {
    int a, c;
    scanf("%d%d", &a, &c);
    v.push_back( cow(a, c) );
  }

  sort( v.begin(), v.end() );

  int time_cur = 0;

  for (int i=0; i<n; i++)
  {
    if ( time_cur < v[i].arrive ) time_cur = v[i].arrive;
    time_cur += v[i].cost;
  }

  printf("%d\n", time_cur);

}
