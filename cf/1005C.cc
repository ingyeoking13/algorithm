#include <stdio.h>
#include <map>
#include <vector>

using namespace std;
int bin[31]={
  1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};

int a[120000];
map<int, vector<int> > m;
int main()
{
  int n; scanf("%d", &n);
  for (int i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
    m[a[i]].push_back(i);
  }

  int ans=0;
  for (int i=0; i<n; i++)
  {
    int chk=0;
    for (int j=0; j<31; j++)
    {
      if ( m.find(bin[j]-a[i]) != m.end())
      {
        for (int k=0; k< m[bin[j]-a[i]].size(); k++)
        {
          if ( i!=m[bin[j]-a[i]][k] ) chk=1;
        }
      }
      if (chk==1) 
      {
        ans++;
        break;
      }
    }
  }
  printf("%d\n", n-ans);

}
