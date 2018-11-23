#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
  int T;
  scanf("%d", &T);

  while(T--)
  {
    int d;
    scanf("%d",&d); 

    if (0<d && d<4) 
    {
      printf("N\n");
      continue;
    }

    printf("Y %.10lf %.10lf\n", ((double)d+sqrt((double)d*d-4*d))/2, ((double)d-sqrt((double)d*d-4*d))/2);
  }


}
