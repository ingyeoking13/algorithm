#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;
int main()
{
  char s1[(int)2e5+1], s2[(int)2e5+1];
  scanf("%s%s", s1, s2);
  string str1 = string(s1);
  string str2 = string(s2);
  reverse(str1.begin(), str1.end());
  reverse(str2.begin(), str2.end());


  int mn = max(str1.length(), str2.length());
  int i;

  for (i=0; i<mn; i++)
  {
    if (str1[i] == str2[i]);
    else break;
  }
  int ans = str1.length()+ str2.length() - 2*i;
  printf("%d\n", ans);

}
