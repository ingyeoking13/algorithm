#include <stdio.h>
#include <vector>

using namespace std;
int main()
{
  int n, m;
  scanf("%d%d",&n,&m);

  vector<int> a(n);
  for (int i=0; i<n; i++)
  {
    scanf("%d",&a[i]);
  }

  int cnt =0, chk =0;
  for (int i=0; i<n; i++)
  {
    if (a[i] ==1 && chk==0)
    {
      chk =1;
      cnt++;
    } else if ( a[i] == 0) chk=0;
  }

  while(m--)
  {
    int op;
    scanf("%d", &op);

    if ( op )
    {
      int idx;
      scanf("%d", &idx);
      idx--;

      if (a[idx] ==1) continue;

      a[idx] =1;

      if (( idx-1 >=0  && a[idx-1] == 1) && (idx+1 < n && a[idx+1] == 1 )) cnt--;
      else if (( idx-1 >=0  && a[idx-1] == 1) || (idx+1 < n && a[idx+1] == 1 ));
      else cnt++;
    }
    else printf("%d\n", cnt);
  }
}
