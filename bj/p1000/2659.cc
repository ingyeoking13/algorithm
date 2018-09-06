#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;
char v[10][10][10][10];
vector<int> ans;
int map[10000];

int a[4]; 
int recv[4];

int can(vector<int> tmp)
{

  for (int i=0; i<4; i++)
  {
    if( v[tmp[i%4]][tmp[(i+1)%4]][tmp[(i+2)%4]][tmp[(i+3)%4]] )
    {
      return 1;
    }
  }
  return 0;
}

void chk(vector<int> tmp)
{
  for (int i=0; i<4; i++)
  {
    v[tmp[i%4]][tmp[(i+1)%4]][tmp[(i+2)%4]][tmp[(i+3)%4]]=1;
  }
}

int main()
{

  for (int i=1; i<=9; i++)
  {
    for (int j=1; j<=9; j++)
    {
      for (int k=1; k<=9; k++)
      {
        for (int l=1; l<=9; l++)
        {
          vector<int> tmp;

          tmp.push_back(i); tmp.push_back(j);
          tmp.push_back(k); tmp.push_back(l);

          if (!can(tmp))
          {

            int min=1e9;
            for (int i=0; i<4; i++)
            {
              int num = tmp[i%4]*1000 + tmp[(i+1)%4]*100 + tmp[(i+2)%4]*10 + tmp[(i+3)%4];
              if (min > num) min = num;
            }

            ans.push_back(min);
            chk(tmp);
          }
        }
      }
    }
  }

  sort(ans.begin(), ans.end());

  for (int i=0; i<ans.size(); i++)
  {
    map[ans[i]] = i+1;
  }

  vector<int> input(4);
  for (int i=0; i<4; i++)
  {
    scanf("%d", &input[i]);
  }

  int min=1e9;
  for (int i=0; i<4; i++)
  {
    int num = input[i%4]*1000 + input[(i+1)%4]*100 + input[(i+2)%4]*10 + input[(i+3)%4];
    if (min > num) min = num;
  }

  printf("%d\n", map[min]);

}
