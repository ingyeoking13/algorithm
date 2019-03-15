#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int a[(int)3e3], presum[(int)3e3];
int main()
{
  int n, m;
  scanf("%d%d\n", &n, &m);

  int r = 0;
  for(int i=0; i<n; i++) 
  {
    scanf("%d", &a[i]);
    r += a[i];
  }
  int l =1; 

  presum[0] = a[0];
  for (int i=1;i<n;i++) presum[i] = presum[i-1] + a[i];

  vector<int> ans;
  int ans_len = 1e9+1;
  while ( l <= r )
  {
    int mid = (l+r)/2;
    int cur = 0, len = 0;
    bool fail = false;
    vector<int> tmp_ans;

    for (int i=0; i<n; i++)
    {
      if ( a[i] > mid ) 
      {
        fail = true;
        break;
      }

      if ( cur + a[i] > mid )
      {
        tmp_ans.push_back( len );
        cur=a[i];
        len=1;
      }
      else 
      {
        cur += a[i]; 
        len++;
      }
    }

    if ( len > 0 ) tmp_ans.push_back( len );

    if ( fail || tmp_ans.size() > m ) l = mid+1;
    else
    {
      int diff =  m - tmp_ans.size();
      ans.clear();

      int i;
      for (i=0;i< tmp_ans.size() && diff > 0 ; i++)
      {
        int elems = tmp_ans[i];
        if ( elems == 1 ) 
        {
          ans.push_back(1);
          continue;
        }

        while ( diff > 0 && elems > 0 )
        {
          ans.push_back(1);
          elems--;
          diff--;
        }
        if (elems > 0 ) ans.push_back(elems);
      }
      for (; i< tmp_ans.size(); i++) ans.push_back( tmp_ans[i] );

      int tmp_len = 0;
      int now = -1, prev = -1;

      for (int i=0; i<ans.size(); i++ )
      {
        now += ans[i];
        int val = presum[now] - (prev!=-1?presum[prev]:0);
        tmp_len = max(tmp_len, val);
        prev = now;
      }
      ans_len = min(ans_len, tmp_len);
      r = mid-1;
    }
  }
  printf("%d\n", ans_len);
  for (int i=0; i< ans.size(); i++) printf("%d ", ans[i]);
  printf("\n");
}
