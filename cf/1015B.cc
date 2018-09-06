#include <stdio.h>
#include <vector>

using namespace std;
char a[51], b[51];
char cnta[26], cntb[26];
vector<int> ans;

void swp(int x, int y) { char tmp = a[x]; a[x]=a[y]; a[y]=tmp;};
int main()
{
  int n;
  scanf("%d", &n);

  scanf("%s%s", a, b);
  for (int i=0; i<n; i++)
  {
    cnta[a[i]-'a']++;
    cntb[b[i]-'a']++;
  }

  for (int i=0; i<26; i++)
  {
    if (cnta[i]!=cntb[i])
    {
      return !printf("-1\n");
    }
  }

  for (int i=0; i<n; i++)
  {
    if (a[i]!=b[i])
    {
      int j=i+1;
      while(j<n && b[i]!=a[j]) j++;
      for (int k=j; k>i; k--)
      {
        swp(k, k-1);
        ans.push_back(k);
      }
    }
  }
  printf("%lu\n", ans.size());
  for(auto i: ans)
  {
    printf("%d ", i);
  }
  printf("\n");
}
