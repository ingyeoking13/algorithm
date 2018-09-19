#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;
char s[101];
bool mycmp(const string& a, const string& b)
{
  if (a.length() == b.length() )
  {
    for (int i=0; i<a.length(); i++)
    {
      if( a[i] > b[i]) return 0;
      else if ( a[i] == b[i] );
      else return 1;
    }
  }
  else return a.length() < b.length();
}

int main()
{
  vector<string> vs;
  int n; scanf("%d", &n);
  for (int i=0; i<n; i++)
  {
    scanf("%s", s);

    int chk=1; // continuos alphabet
    int first=1; // first number at a line
    int len = strlen(s);

    for (int j=0; j<len; j++)
    {
      if ( s[j] <='9' && s[j] >='0' && chk==1)
      {
        if (first==1)
        {
          first=0;
          vs.push_back("");
          vs.back().push_back(s[j]);
        }
        else
        {
          vs.back().push_back(s[j]);

          if (s[j] <= '9' && s[j]>='0')
          {
            if(vs.back()[0]=='0')
            {
              vs.back().erase(0,1);
            }
          }

        }
      }
      else if( chk== 0 && s[j] <= '9' && s[j] >='0')
      {
        vs.push_back("");
        vs.back().push_back(s[j]);
        first=0;
        chk=1;
      }
      else chk=0; 
    }
  }

  sort(vs.begin(), vs.end(), mycmp);
  for (int i=0; i<vs.size(); i++)
  {
    printf("%s\n", vs[i].c_str());
  }
}
