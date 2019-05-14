#include <iostream>
#include <string.h>
using namespace std;

char s[52];
int main()
{
  cin >> s;

  int len =strlen(s);
  int mid = (len-1)/2;
  char ans[52];
  char ansLen=0;

  int idx = 1;
  char state = 0;

  len--;
  ans[ansLen++] = s[mid];

  while ( len -- )
  {
    ans[ansLen ++] = s[mid + idx];

    if (state) 
    {
      idx = -idx;
      idx++;
      state = 0;
    }
    else 
    {
      state = 1;
      idx = -idx;
    }
  }
  ans[ansLen] = 0;
  cout << ans << "\n";

}
