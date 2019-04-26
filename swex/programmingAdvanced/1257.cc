#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;
int main()
{

  int T;
  int tt=0;
  cin >> T;
  while (++tt<=T)
  {
    int n;
    cin >> n;
    string str;
    cin >> str;

    set<string> v;
    for (int i=0; i<str.size(); i++)
    {
      for (int j=i; j<str.size(); j++)
      {
        v.insert(str.substr(i, j-i+1));
      }
    }
    if ( n > v.size() )
    {
      cout << "#" << tt << " none\n";
    }
    else 
    {
      set<string>::iterator it = v.begin();
      for (int i=0; i< n-1; i++)
      {
        it++;
      }
      cout << "#" << tt << " " << *(it) << "\n";
    }
  }

}
