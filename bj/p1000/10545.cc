#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int al[26] = {
  12, 22, 32, 13, 23, 33,
  14, 24, 34, 15, 25, 35,
  16, 26, 36, 17, 27, 37, 47,
  18, 28, 38, 19, 29, 39, 49
};

int b[10];
char s[102];

int main()
{
  for (int i=1; i<=9; i++)
  {
    int tmp;
    cin >> tmp;
    b[tmp] = i;
  }

  cin >> s;

  int len = strlen(s);
  char prev = -1;

  vector<char> ans;

  for (int i=0; i<len; i++)
  {
    char c = s[i];


    int number = al[c-'a'];

    int dial = number%10;
    int time = number/10;

    char cur_push = b[dial]+'0';
    if ( prev == cur_push ) 
    {
      ans.push_back('#');
    }

    for (int j=0; j<time; j++)
    {
      ans.push_back(cur_push);
    }

    prev = cur_push;
  }

  for (int i=0; i<ans.size(); i++)
  {
    cout << ans[i];
  }

}
