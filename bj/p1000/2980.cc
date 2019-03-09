#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct light
{
  int d, r, g;
  bool operator< (light & a ) { return d < a.d; };
};

int main()
{
  int n, l;
  scanf("%d%d", &n, &l);

  vector<light> v(n);
  for (int i=0; i<n; i++ ) scanf("%d %d %d", &v[i].d, &v[i].r, &v[i].g);


  sort(v.begin(), v.end());

  int pos=0;
  int faced_light=0;
  int time=0;

  while ( pos < l )
  {
    if ( pos != v[faced_light].d ) pos++;
    else 
    {
      int cycle = v[faced_light].r + v[faced_light].g;
      if ( time%cycle  >= v[faced_light].r )
      {
        pos++;
        faced_light++;
      }
    }
    time++;
  }
  printf("%d\n", time);
}
