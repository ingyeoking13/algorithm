//#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
  /*
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  */
  double h, l;
  scanf("%lf %lf", &h, &l);
  printf("%.11lf\n",(h*h+l*l)/(2*h) - h);
}

