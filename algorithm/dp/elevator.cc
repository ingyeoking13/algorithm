/* 181205 0650 AM Start, ... 잠깐포트나이트좀하고
   181205 0750 AM 노래 들으면서 다시 시작 
 */
// 난이도 scpc 본선문제 "재활용" 보다 어려움  codeground 에서 활용가능

#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

struct Person
{
  int dest, up, down;
  Person(int dest, int up, int down) : dest(dest), up(up), down(down){};
};
vector<Person> a;

int d[500][201];
int mincost[200][200];

int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
  {

    a.clear();
    memset(d, 0, sizeof(d));
    memset(mincost, 0, sizeof(mincost));

    int n, m;
    scanf("%d%d", &n, &m);
    int mx = 0;

    for (int i=0; i<n; i++)
    {
      int dest, up, down;
      scanf("%d%d%d", &dest, &down, &up);
      a.push_back(Person(dest, up, down));
      if (dest > mx) mx=dest;
    }

    for (int i=1; i<=200; i++)
    {
      for (int j=i; j<=200; j++)
      {
        for (int k=0; k<a.size(); k++)
        {
          if ((a[k].dest >= i) && (a[k].dest <= j))
          {
            mincost[i][j] += min( 
                                  a[k].up * ( a[k].dest - i), 
                                  a[k].down * (j- a[k].dest)

                                );  

          }
        }
      }
    }

    for (int i=1; i<=200; i++)
    {
      d[i][1] = mincost[1][i];
      for (int j=2; j<= min(i, m); j++)
      {
        d[i][j] = (int)1e9;
        for (int k=1; k<i; k++)
        {
          d[i][j] = min(d[i][j], d[k][j-1] + mincost[k][i]);
        }
      }
    }

    printf("%d\n", d[mx][m]);

    int ans = (int)1e9;
    for (int i=m; i<=200; i++)
    {
      int sum=0;
      for (int j=0; j<n; j++)
      {
        if (a[j].dest >= i) sum += (a[j].up * (a[j].dest - i));
      }
      ans = min(ans, d[i][m] + sum);
    }

    printf("%d\n", ans);
  }

}
