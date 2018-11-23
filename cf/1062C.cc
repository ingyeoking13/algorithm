#include <stdio.h>

using namespace std;

char s[(int)1e5+3];
int cnt[(int)1e5+1];
int pp[(int)1e5+1];

int main()
{
  freopen("in.txt", "r", stdin);
  int n, q;
  scanf("%d %d", &n, &q);
  scanf("%s", s+1);

  cnt[1] = (s[1]=='1');
  for (int i=2; i<=n; i++) 
  {
    cnt[i] = cnt[i-1] + (s[i] == '1');
  }

  pp[1]=1;

  long long tmp=1;
  for (int i=2; i<=1e5; i++)
  {
    tmp*=2;
    tmp= tmp%((int)1e9+7);
    pp[i]=pp[i-1]+tmp;
    pp[i]= pp[i]%((int)1e9+7);
  }

  while(q--)
  {
    int l, r;
    scanf("%d %d", &l, &r);

    int len = r-l+1;
    int one = cnt[r] - cnt[l-1];

    if (one == 0) 
    {
      printf("0\n");
      continue;
    }

    long long ans=pp[one];
    int t = (len-one)/30;

    for (int i=0; i<t; i++) 
    {
      ans=ans<<30;
      ans= ans%((int)1e9+7);
    }
    for (int i=0; i<(len-one)%30; i++)
    {
      ans= ans<<1;
      ans = ans%((int)1e9+7);
    }
    printf("%d\n", ans);
  }
}
