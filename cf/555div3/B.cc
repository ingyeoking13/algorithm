#include <iostream>

using namespace std;
char s[(int)2e5+3];
int a[10];
int main()
{
  int n;
  cin >> n;
  cin >> s;
  for (int i=1; i<=9; i++) cin >> a[i];
  
  bool chk =false;

  for (int i=0; i<n; i++)
  {
    int now = s[i]-'0';
    if( now < a[now] )
    {
      s[i] = a[now]+'0';
      chk = true;
    }
    else if ( now > a[now] && chk) break;
  }
  cout << s <<"\n";
}
