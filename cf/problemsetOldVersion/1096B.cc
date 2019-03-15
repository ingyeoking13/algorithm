#include <iostream>
#define MOD 998244353

using namespace std;
int main()
{
  int n;
  cin >> n;

  string s;
  cin >> s;


  char front = s[0];
  bool chk=1;
  for (int i=1; i<s.size(); i++)
  {
    if (front != s[i]) chk=0;
  }

  if ( chk ) // 다 똑같다면
  {
    long long ans=0;
    ans += (1L*s.size()*(s.size()-1)/2)%MOD;
    ans += s.size();
    ans%=MOD;
    cout << ans << "\n";
    return 0;
  }

  if ( front == s[s.size()-1] )
  {
    int cnt1=0;
    for (int i=0; i<s.size(); i++)
    {
      if (s[i] == front) cnt1++;
      else break;
    }

    int cnt2=0;
    for (int i=s.size()-1; i>=0; i--)
    {
      if (s[i] == front) cnt2++;
      else break;
    }
    long long ans=0;

    ans += (1L*(cnt1+1)*(cnt2+1))%MOD;

    ans%=MOD;
    cout << ans << "\n";
    return 0;
  }

  int cnt1=0;
  for (int i=0; i<s.size(); i++)
  {
    if (s[i] == front) cnt1++;
    else break;
  }
  int ans = (cnt1);

  int cnt2=0;
  for (int i=s.size()-1; i>=0; i--)
  {
    if (s[i] == s[s.size()-1]) cnt2++;
    else break;
  }
  ans += cnt2;
  ans++;
  cout << ans << "\n";
}
