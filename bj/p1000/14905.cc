#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

char p[(int)1e8+1];
vector<int> pset;

int main()
{
  p[0] = p[1] = 1;
  for (int i=2; i*i<=1e8; i++)
  {
    if (p[i] == 0)
    {
      pset.push_back(i);
      for (int j=i+i; j<=1e8; j+=i) p[j] =1;
    }
  }

  int n;
  while(~scanf("%d", &n))
  {
    bool chk=0;
    if ( n <8 ) 
    {
      printf("Impossible.\n");
      continue;
    }

    if (n%2 == 0)
    {
      for (int i=2; i<=(n-4); i++)
      {
        if ( !p[i] && !p[(n-4)-i] )
        {
          chk=1;
          printf("2 2 %d %d\n", i, (n-4)-i);
          break;
        }
      }
    }
    else
    {
      for (int i=2; i<=(n-5); i++)
      {
        if ( !p[i] && !p[(n-5)-i] )
        {
          chk=1;
          printf("2 3 %d %d\n", i, (n-5)-i);
          break;
        }
      }
    }
    if (!chk) printf("Impossible.\n");
  }
}
