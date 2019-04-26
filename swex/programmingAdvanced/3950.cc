#include <iostream>

using namespace std;

struct data
{
  int f, t;
  data() {};
  data(int f, int t ) : f(f), t(t) {};
};

char str[(int)1e3+5];

int st[(int)1e3];
int top;

data ans[(int)1e3];
int anslen;
int p[(int)1e3];

int main()
{

  int T;
  int tt =0; 
  cin >> T;
  while (++tt<= T)
  {
    anslen = 0;
    top = -1;

    int n;
    cin >> n;
    cin >> str;

    if ( n%2 == 1 )
    {
      cout << "#" << tt << " " << -1<<"\n";
      continue;
    }

    if (str[0] == ')' ) p[0] =-1;
    else p[0] = 1;

    for (int i=1; i<n; i++)
    {
      if ( str[i] == ')' ) p[i]= p[i-1]-1;
      else p[i] = p[i-1]+1;
    }

    for (int i=0 ; i<n; i++) cout << p[i];
    cout << "\n";

    for (int i=0; i<n; i++)
    {
      d[i] = d[i];
    }

  }
}
