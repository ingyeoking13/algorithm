#include <string>
#include <iostream>

using namespace std;

char t['Z'+1]['Z'+1];
int main()
{
  int n;
  string str;
  cin >> n >> str;
  t['A']['A'] = t['A']['C'] = t['G']['T'] = t['T']['G'] = t['C']['A'] = 'A';
  t['A']['T'] = t['G']['G'] = t['T']['A'] = t['T']['C'] = t['C']['T'] = 'G';
  t['A']['G'] = t['G']['A'] = t['C']['C'] ='C';
  t['G']['C'] = t['C']['G'] = t['T']['T'] ='T';

  while(str.size() !=1 )
  {
    int len = str.size();
    char one = str[len-2];
    char two = str[len-1];

    str.erase(str.end()-1);
    str[str.size()-1] = t[one][two];
  }

  cout << str <<"\n";

}
