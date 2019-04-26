#include <iostream>
#include <string.h>

using namespace std;

int main()
{
  char str[(int)1e6+1];
  int pi[(int)1e6];
  while (1)
  {
    cin >> str;
    if  ( str[0] == '.' ) break;

    int len = strlen(str);
    pi[0] = 0;

    int matched=0;
    for (int i=1; i<len; i++)
    {
      if ( str[i] == str[matched] )
      {
        pi[i] = ++matched;
      }
      else pi[i] =matched = 0;
    }

    for (int i=0; i<len; i++)
    {
      cout << pi[i] << " " ;
    }
    cout << "\n";
  }

};
