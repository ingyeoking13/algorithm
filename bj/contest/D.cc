#include <stdio.h>

int ret(char* s)
{
  int r=0;
  for (int i=0; s[i]; i++)
  {
    if (s[i]=='\n') continue;
    r*=10;
    if (s[i] == '0' || s[i] == '6') r += 9;
    else r += (s[i]-'0');
  }
  if (r >100 ) r=100;
  return r;
}

int main()
{
  int n;
  scanf("%d", &n);
  int ans=0;
  for (int i=0; i<n; i++)
  {
    char s[5];
    scanf("%s", s);

    int d = ret(s);
    ans+=d;
  }
  printf("%.0lf\n", (double)ans/n);

}
