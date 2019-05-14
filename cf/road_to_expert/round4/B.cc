#include <iostream>
#include <algorithm>

using namespace std;

int a[100];
int main()
{
  int n;
  cin >> n;
  for (int i=0; i<n; i++)
  {
    cin >> a[i];
  }
  sort(a, a+n);

  int my=0;
  for (int i=0; i<n; i++)
  {
    my += a[i];
  }

  double target = (4.5*(double)n); 

  int i =0;
  while (my < target )
  {
    my -= a[i];
    my += 5;
    i++;
  }
  cout << i <<"\n";
}
