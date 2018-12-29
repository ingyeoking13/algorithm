#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> s;

bool mycmp(string a, string b)
{
  if (a.length() == b.length()) return a > b; 

  int i=0;
  for (;i< a.size() && i<b.size(); i++)
  {
    if ( a[i] != b[i]) return a[i] > b[i];
  }

  for (int j=0; i < a.size() ; j++, i++ )
  {
    if (j==b.size())  j=0;
    if (b[j] != a[i] ) return a[i] > b[j];
  }

  for (int j=0; i < b.size(); j++, i++)
  {
    if (j==a.size()) j=0;
    if (a[j] != b[i] ) return a[j] > b[i];
  }

  return 0;
}

int main()
{
  int n;
  scanf("%d", &n);

  for (int i=0; i<n; i++)
  {
    char tmp[20];
    scanf("%s", tmp);
    s.push_back(tmp);
  }

  sort(s.begin(), s.end(), mycmp);

  if (s[0][0] =='0') return !printf("0\n");
  for (int i=0; i<s.size(); i++)
  {
    printf("%s",s[i].c_str());
  }
  printf("\n");

}
