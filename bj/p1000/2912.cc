#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int main()
{
  int n, c;
  scanf("%d%d", &n, &c);
  vector<int> a(n);
  vector<vector<int>> col(c+1);

  for (int i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
    col[a[i]].push_back(i);
  }

  int m;
  scanf("%d", &m);

  while(m--)
  {
    int ql, qr;
    scanf("%d%d", &ql, &qr);
    ql--, qr--;
    bool chk=false;
    for (int t=0; t<50; t++)
    {
      int i = (int)rand();
      i %= (qr-ql+1);
      i += ql;
      if ( col[a[i]].size() == 0) continue;

      int selected_color = a[i];

      int l = 0, r = col[ selected_color ].size()-1; 

      int left=-1, right=-1; 
      while ( l<=r )
      {
        int m = (l+r)/2;

        if ( col[selected_color][m] >= ql )
        {
          left = m;
          r = m-1;
        }
        else l = m+1;
      }

      l = 0, r= col[ a[i] ].size()-1;
      while ( l<= r )
      {

        int m = (l+r)/2;
        if ( col[selected_color][m] <= qr ) l= m+1;
        else r = m-1, right = mc
      }

      int len=0;
      if ( right <0 ) len =  col[ selected_color ].size() -left;
      else len = right-left;
      if (len > (qr-ql+1)/2 )
      {
        printf("yes %d\n", a[i]);
        chk=true;
        break;
      }
    }
    if (!chk) printf("no\n");
  }
}
