#include <stdio.h>
#include <vector>

using namespace std;

vector<int> e[(int)2e5+1];
vector<int> p[(int)2e5+1];
int ans[(int)2e5];

int main()
{
  int n;
  scanf("%d", &n);

  for (int i=1; i<=n; i++)
  {
    int v1, v2;
    scanf("%d%d", &v1, &v2);
    e[i].push_back(v1);
    e[i].push_back(v2);
    p[v1].push_back(i);
    p[v2].push_back(i);
  }
  ans[n-2]=1;
  int now =1;

  for (int i=0; i<n-2; i++)
  {
    int pp1 = p[now][0];
    int pp2 = p[now][1];

    if ( e[pp1][0] == e[now][0] ||  e[pp1][1] == e[now][0] )    ans[n-3-i] = pp1, now=pp1;
    else if( e[pp1][0] == e[now][1] || e[pp1][1] == e[now][1] ) ans[n-3-i] = pp1, now=pp1;
    else if ( e[pp2][0] == e[now][0] || e[pp2][1] == e[now][0]) ans[n-3-i] = pp2, now=pp2;
    else if ( e[pp2][0] == e[now][1] || e[pp2][1] == e[now][1]) ans[n-3-i] = pp2, now=pp2;

  }

  if (e[ans[n-3]][1] !=1) ans[n-1] = e[ans[n-3]][1];
  else ans[n-1] = e[ans[n-3]][0];

  for (int i=0; i<n; i++) printf("%d ", ans[i]);

}
