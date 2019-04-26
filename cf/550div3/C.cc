#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int a[(int)2e5];
int hit[(int)2e5+1];
vector<int> in, de;
int main()
{
  int n;
  scanf("%d", &n);

  for (int i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
    if (hit[a[i]] == 0) 
    {
      in.push_back(a[i]);
      hit[a[i]]++;
    }
    else if(hit[a[i]]==1)
    {
      de.push_back(-a[i]);
      hit[a[i]]++;
    }
    else return !printf("NO\n");
  }

  sort(in.begin(), in.end());
  sort(de.begin(), de.end());

  printf("YES\n");
  printf("%lu\n", in.size());
  for (int i=0; i<in.size(); i++)
  {
    printf("%d ", in[i]);
  }
  printf("\n");
  printf("%lu\n", de.size());
  for (int i=0; i<de.size(); i++)
  {
    printf("%d ", -de[i]);
  }
  printf("\n");

}
