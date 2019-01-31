#include <stdio.h>
#define CHKPOINT (int)(2e5+5e4)

using namespace std;
struct point
{
  int x, y;
  point(int x, int y) : x(x), y(y) {} ;
};

point a[CHKPOINT];
int p[CHKPOINT];

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);

  for (int i=0; i<n; i++) p[i]=i;

  for (int i=0; i<n; i++)
  {
    int x, y;
    scanf("%d %d", &x, &y);
    a[i] = point(x, y);
  }

  while(m--)
  {
    int u, v, HP;
    scanf("%d%d%d",&u,&v,&HP);






  }

}
