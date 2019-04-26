#include <stdio.h>
#include <string>
#include <map>

using namespace std;
int main()
{
  freopen("evolution.in", "r", stdin);
  freopen("evolution.out", "w", stdout);

  int n;
  scanf("%d", &n);
  map<string, bool> m;

  char s[5000];
  for (int i=0; i<n; i++)
  {
    int mm;
    scanf("%d",&mm);
    if (mm == 0) continue;
    fgets(s, 5000, stdin);

    string str = string(s);
    if (m.find(str) == m.end() )
    {
      m[str] = true;
    }
    else printf("no\n");
  }
  printf("yes\n");
}
