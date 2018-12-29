#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

bool query[26][26];
int main()
{
  int n;
  scanf("%d", &n);
  vector<int> e[26];
  for (int i=0; i<n; i++)
  {
    char u[3], v[3];
    scanf("%s is %s", u, v);

    e[u[0]-'a'].push_back(v[0]-'a');
    query[u[0]-'a'][v[0]-'a']= true;
  }
  for (int i=0; i<26; i++)
  {
    queue<int> q;
    q.push(i);
    vector<bool> v(26);
    v[i]=true;

    
    while(!q.empty())
    {
      int now = q.front();
      q.pop();
      for (int j=0; j<e[now].size(); j++)
      {
        if ( v[e[now][j]] ) continue;
        v[e[now][j]] =true;
        q.push(e[now][j]);
        query[i][e[now][j]] = true;
      }
    }
  }

  int m;
  scanf("%d", &m);

  while(m--)
  {
    char u[3], v[3];
    scanf("%s is %s", u ,v);

    if (query[u[0]-'a'][v[0]-'a']) printf("T\n");
    else printf("F\n");

  }
}
