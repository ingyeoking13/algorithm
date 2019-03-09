#include <stdio.h>
#include <algorithm>

using namespace std;

int a[(int)1e5];
int main()
{

  int n;
  scanf("%d", &n);

  for (int i=0; i<n; i++) scanf("%d", &a[i]);

  int prevdown=0, prevup=0;
  int Q;
  scanf("%d", &Q);

  int top = -1;
  int stack[(int)1e5];
  int l =0, r=0;
  while(Q--)
  {
    int up, down;
    scanf("%d%d", &up, &down);
    up--, down--;


  }
  int sort_len =0, state=0;
  for (int i=n-1; i>=0; i--)
  {
    if ( st[i] != 0) 
    {
      sort_len=i+1;
      state = st[i];
      break;
    }
  }
  if (state == 0)
  {
    for (int i=0; i<n; i++)
    {
      printf("%d ", &a[i]);
    }
    printf("\n");
    return 0;
  }

  if ( state == 1)
  {
    sort(a, a+sort_len);
  }
  else if ( state == -1)
  {
    for(int i=0; i<sort_len; i++) a[i] = -a[i];
    sort(a, a+sort_len);
    for(int i=0; i<sort_len; i++) a[i] = -a[i];
  }

  deque<int>  ans;
  for (int i=n-1; i>=0; i--)
  {
    if ( st[i] == 0 && curst==0) ans.push_back(a[i]);
    else if ( st[i] == state || curst == state)
    {
      ans.push_back(


    }


  }



}
