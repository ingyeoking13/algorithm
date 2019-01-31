#include <iostream>
#include <string>

using namespace std;
struct pos
{
  int r, c;
  pos(int r, int c) : r(r), c(c) {};
};

int main()
{
  string str;
  cin >> str;

  char ver=0;

  char hor=0;

  for (int i=0; i<str.size(); i++)
  {
    if ( str[i] == '0' )
    {
      if ( ver == 1)
      {
        cout << "3 1\n";
        ver=0;
      }
      else
      {
        cout << "1 1\n"; 
        ver=1;
      }
    }
    else if (str[i] == '1' )
    {
      if ( hor == 1)
      {
        cout << "4 1\n";
        hor=0;
      }
      else 
      {
        cout << "4 3\n";
        hor=1;
      }
    }
  }
}
