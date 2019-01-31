#include <iostream>
#include <string>
#include <stack>

using namespace std;
stack<char> s;

int main()
{
  string str;
  cin >> str;

  char turn = 1;
  for (int i=0; i<str.size(); i++)
  {
    if ( s.empty() ) 
    {
      s.push(str[i]);
    }
    else
    {
      if ( s.top() == str[i] )
      {
        s.pop();
        turn = 3-turn;
      }
      else s.push(str[i]);
    }
  }

  if (turn == 1) cout << "No\n";
  else cout << "Yes\n";


}
