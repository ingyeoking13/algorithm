#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;
int dr[8] = {3, 3, -3, -3, 2, 2, -2, -2};
int dc[8] = {-2, 2, -2, 2, -3, 3, -3, 3};
int Kr, Kc;

int d[10][9];
queue<pair<int, int> > q;

int main()
{
  int Sr, Sc;
  scanf("%d%d%d%d", &Sr, &Sc, &Kr, &Kc);

  q.push({Sr, Sc});
  memset(d, 0x7f, sizeof(d));
  d[Sr][Sc] = 0;

  while(!q.empty())
  {
    auto now = q.front();
    q.pop();

    int r = now.first;
    int c = now.second;

    if ( r == Kr && c == Kc ) continue;

    for (int i=0; i<8; i++)
    {
      int nr = r+dr[i], nc = c+dc[i];

      if ( nr >=0 && nc >= 0 && nr <=9 && nc <= 8 )
      {
        // stuck check start
        bool chk=0; // stuck check

        int testr = r, testc = c;
        int unitr = dr[i]>0?1:-1;
        int unitc = dc[i]>0?1:-1;

        if (abs(dr[i]) > abs(dc[i]))
        {
          if (dr[i] > 0) testr++;
          else testr--;
        }
        else
        {
          if (dc[i] >0 ) testc++;
          else testc--;
        }

        if (testr == Kr && testc  == Kc ) continue;
        for (int j=0; j<1; j++)
        {
          testr += unitr;
          testc += unitc;
          if (testr == Kr && testc == Kc) chk=1;
        }
        if (chk) continue;

        //stuck chk end

        if ( d[nr][nc] > d[r][c]+1 )
        {
          d[nr][nc] = d[r][c] +1;
          q.push({nr, nc});
        }
      }
    }
  }

  int ans = d[Kr][Kc];
  if (ans == 0x7f7f7f7f) printf("-1\n");
  else printf("%d\n",ans);
}
